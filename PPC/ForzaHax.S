#
# mojobojo 2011
# Forza 4 savegame crypto bypass
#

# Skip the savegames hash verification
.long 0x82962CC8
.long ( 1f - 0f ) / 4
0:
		# Original code
	nop # bne       loc_82962D24
1:

# Skip the decryption
.long 0x82962CEC
.long ( 1f - 0f ) / 4
0:
		# Original code
	nop # bl        XeKeysAesCbcUsingKey
	nop # cmpwi     r3, 0
	nop # blt       loc_82962D24
1:

# Skip the encryption
.long 0x82962E50
.long ( 1f - 0f ) / 4
0:
		# Original code
	nop # bl        XeKeysAesCbcUsingKey
	nop # cmpwi     r3, 0
	nop # blt       loc_82962F04
1:

.long 0xFFFFFFFF
