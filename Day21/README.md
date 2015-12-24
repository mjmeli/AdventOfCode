## Day 21

#### Problem
Little Henry Case got a new video game for Christmas. It's an RPG, and he's stuck on a boss. He needs to know what equipment to buy at the shop. He hands you the controller.

In this game, the player (you) and the enemy (the boss) take turns attacking. The player always goes first. Each attack reduces the opponent's hit points by at least 1. The first character at or below 0 hit points loses.

Damage dealt by an attacker each turn is equal to the attacker's damage score minus the defender's armor score. An attacker always does at least 1 damage.

Your damage score and armor score both start at zero. They can be increased by buying items in exchange for gold. You start with no items and have as much gold as you need. Your total damage or armor is equal to the sum of those stats from all of your items. You have 100 hit points.

The items that the shop is selling can be found in `shop.txt`.

Purchasing rules:
* You must buy exactly one weapon; no dual-wielding.
* Armor is optional, but you can't use more than one.
* You can buy 0-2 rings (at most one for each hand).
* You must use any items you buy.
* The shop only has one of each item, so you can't buy, for example, two rings of Damage +3.

##### Part 1
You have 100 hit points. The boss's actual stats are in `boss.txt`. What is the
**least** amount of gold you can spend and still **win** the fight?

##### Part 2
Turns out the shopkeeper is working with the boss, and can persuade you to buy whatever items he wants. The other rules still apply, and he still only has one of each item.

What is the **most** amount of gold you can spend and still **lose** the fight?

#### Solution
This solution was brute-forced. I checked every possible combination and simulated
the battle to determine the winner, and then checked the gold cost.

One trick I implemented was instead of simulating the battle back-and-forth, I
used an equation I came up with to determine the number of turns that each
combatant would require to defeat the other. This number can be compared to
easily find the winner.

To be able to do this approach while including the options to not wear armor or
rings, I added dummy items to my code's representation of the shop with 0 cost, 0
damage, and 0 armor.

Other than that, this solution was simple.

`day21.c` - C code that implements solution

`day21.h` - Header file containing struct definitions mainly
