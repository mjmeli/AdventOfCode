from spells import *

"""
    The Player class represents the player in the problem. A player can have
    various attributes, mainly health (hit points), mana, and armor. This class
    is also used to track all the Effects lingering from prior Effect spells.
    Finally, this class tracks mana spent across all casts.
"""
class Player:
    def __init__(self, health, mana):
        self.health = health
        self.mana = mana
        self.armor = 0
        self.effects = []
        self.manaSpent = 0

    # Is the player dead?
    def isDead(self):
        return (self.health <= 0)

    # Is the player able to cast this spell? Check that there is enough mana,
    # and in the case of an effect, that the effect is not already active.
    def canCast(self, spell):
        if spell.cost > self.mana:
            return False
        if not isinstance(spell, Effect):
            return True
        # If we are here, the spell is an effect. The effect cannot be active,
        # unless the effect is going to expire this turn.
        for effect in self.effects:
            if type(effect) == type(spell) and effect.timer > 0:
                return False
        return True

    # Cast a spell. Add the spell's mana cost to mana spent and either directly
    # apply it if it is a Spell or begin it if it is an Effect.
    def cast(self, spell, defender):
        self.manaSpent = self.manaSpent + spell.cost
        # Check if the spell is an Effect or not
        if isinstance(spell, Effect):
            spell.begin(self)           # begin the effect
            self.effects.append(spell)  # track effect for applying later turns
        else:
            spell.apply(self, defender) # immediately apply the spell

    # Apply every effect currently active. If the effect is expiring, remove it.
    def applyEffects(self, defender):
        toRemove = []
        for effect in self.effects:
            if effect.apply(self, defender) == 0 and not isinstance(effect, Shield):
                toRemove.append(effect)
        for effect in toRemove:
            self.effects.remove(effect)

    # Remove any effects that are expiring
    def removeEffects(self):
        toRemove = []
        for effect in self.effects:
            if effect.timer == 0:
                toRemove.append(effect)
        for effect in toRemove:
            self.effects.remove(effect)
            if isinstance(effect, Shield):
                effect.end(self)

"""
    The Boss class represents the boss in the problem. The boss only has two
    attributes: health and damage. The boss only has one type of attack.
"""
class Boss:
    def __init__(self, health, damage):
        self.health = int(health)
        self.damage = int(damage)

    # Is the boss dead?
    def isDead(self):
        return (self.health <= 0)

    # Carry out an attack. The amount of the attack is the difference in the
    # boss' damage and the attacked's armor. If this difference is less than 1,
    # the boss will still deal 1 damage.
    def attack(self, defender):
        attackAmount = max(1, self.damage - defender.armor)
        defender.health = defender.health - attackAmount
