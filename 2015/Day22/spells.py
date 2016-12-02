""" General class for a spell """
class Spell:
    def __init__(self, name, cost, damage, heal):
        self.name = name
        self.cost = cost
        self.damage = damage
        self.heal = heal

    # Apply the effects of the spell
    def apply(self, caster, defender):
        caster.mana = caster.mana - self.cost
        caster.health = caster.health + self.heal
        defender.health = defender.health - self.damage

""" An Effect is a spell that lasts for multiple turns based off a timer. """
class Effect(Spell):
    def __init__(self, name, cost, damage, heal, armor, mana, timer):
        Spell.__init__(self, name, cost, damage, heal)
        self.armor = armor
        self.mana = mana
        self.timer = timer

    # Begin casting the effect. This involves taking out the mana cost and
    # applying passive effects (armor).
    def begin(self, caster):
        caster.mana = caster.mana - self.cost
        caster.armor = caster.armor + self.armor

    # Apply the effects of the spell. Since this is an effect, this also means
    # reducing the timer. If the timer hits zero, remove any passive effects.
    def apply(self, caster, defender):
        caster.health = caster.health + self.heal
        caster.mana = caster.mana + self.mana
        defender.health = defender.health - self.damage
        self.timer = self.timer - 1
        return self.timer

    # Remove the passive effects of the spell (armor).
    def end(self, caster):
        caster.armor = caster.armor - self.armor

"""
    The following classes represent each of the spells that can be used by the
    caster for this problem. Ones that inherit from Spells are simply spells,
    while those that inherit from Effect.
"""

class MagicMissile(Spell):
    def __init__(self):
        Spell.__init__(self, "Magic Missile", 53, 4, 0)

class Drain(Spell):
    def __init__(self):
        Spell.__init__(self, "Drain", 73, 2, 2)

class Shield(Effect):
    def __init__(self):
        Effect.__init__(self, "Shield", 113, 0, 0, 7, 0, 6)

class Poison(Effect):
    def __init__(self):
        Effect.__init__(self, "Poison", 173, 3, 0, 0, 0, 6)

class Recharge(Effect):
    def __init__(self):
        Effect.__init__(self, "Recharge", 229, 0, 0, 0, 101, 5)
