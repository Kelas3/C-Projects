#ifndef BIT_MACROS_H

#define BIT_MACROS_H

#define IsOn(x,y)((0u == (x & (1 << y))) ? 0u : 1u)
#define TurnOn(InBit, Loc) (InBit |= (1 << Loc))
#define TurnOff(InBit, Loc) (InBit &= ~(1 << Loc))
#define Toggle(InBit, Loc) (InBit ^= (1 << Loc))

#endif
