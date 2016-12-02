import sys, random, time, copy
from spells import *
from players import *
from enum import Enum

""" Possible results from each turn """
class TurnResult(Enum):
    none = 0
    player_cant_cast = 1
    player_dead = 2
    boss_dead = 3

""" Execute a Player's turn """
def playerTurn(player, boss, spell, hardMode):
    # If in hard mode (part 2), reduce HP by 1 at beginning
    if hardMode:
        player.health = player.health - 1
        if player.isDead():
            return TurnResult.player_dead

    # Cast all effects at the beginning of the turn
    player.applyEffects(boss)

    # Ensure the player can cast; if so, cast the spell
    if player.canCast(spell):
            player.cast(spell, boss)
    else:
        return TurnResult.player_cant_cast

    # Check if this cast has killed the boss
    if boss.isDead():
        return TurnResult.boss_dead

    # Remove any effects that expire in this turn
    player.removeEffects()

    return TurnResult.none

""" Execute a Boss' turn """
def bossTurn(player, boss):
    # Cast all effects at the beginning of the turn and see if they kill the boss
    player.applyEffects(boss)
    if boss.isDead():
        return TurnResult.boss_dead

    # Have the boss attack the player and see if the player is dead
    boss.attack(player)
    if player.isDead():
        return TurnResult.player_dead

"""
    Driving code for solving the problem. First, read command line input for
    the starting conditions. Then, simulate parts 1 and 2 by randomly carrying
    out a battle. In each player's turn, a random spell is chosen and cast.
    When the boss is killed, the amount of mana spent is tallied and compared
    to the running minimum.
"""
# Read command line input for starting conditions
playerHP = int(sys.argv[1])
playerMana = int(sys.argv[2])
bossHP = int(sys.argv[3])
bossDamage = int(sys.argv[4])

# Randomly simulate the battle many times to converge on the solution
numIterations = 1000000
spells = [MagicMissile(), Drain(), Shield(), Poison(), Recharge()]
for j in range(1,3):
    minMana = 9999
    hardMode = (j == 2)
    for i in range(numIterations):
        completion = i / numIterations
        print("Progress: {:2.2%}".format(completion), end="\r")

        # Reset players to starting conditions
        player = Player(playerHP, playerMana)
        boss = Boss(bossHP, bossDamage)

        # Play until a result ends the game
        while True:
            # Choose a random spell to cast
            choice = copy.deepcopy(random.choice(spells))

            # Player goes first. Check if the boss is dead or mana runs out.
            playerRes = playerTurn(player, boss, choice, hardMode)
            if playerRes == TurnResult.boss_dead and player.manaSpent < minMana:
                minMana = player.manaSpent  # update minMana if boss dies
                break
            elif playerRes == TurnResult.player_cant_cast or playerRes == TurnResult.player_dead:
                break   # player loses if can't cast or dead

            # Boss goes next. Check if the boss or player dies.
            bossRes = bossTurn(player, boss)
            if playerRes == TurnResult.boss_dead and player.manaSpent < minMana:
                minMana = player.manaSpent  # update minMana if boss dies
                break
            elif bossRes == TurnResult.player_dead:
                break   # player loses if dies

            # Stop early if current mana spent is larger than minimum
            if (player.manaSpent > minMana):
                break

    # Print results
    print("Part %d: Minimum mana is %d." % (j, minMana))
