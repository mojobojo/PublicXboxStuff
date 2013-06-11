#
# Commented by Mojobojo 2010
#
# Think of it as a C function. The first argument of the function is r3, then r4 is the second, etc.
# This function is the same as 
#		DWORD GenerateChecksum(BYTE *data, DWORD size)
#
.text:827ED498 GenerateChecksum:
.text:827ED498
.text:827ED498                 cmplwi  cr6, %r4, 4			# We want to see if the data size is larger than four
.text:827ED49C                 bge     cr6, ChecksumInit	# If it is, continue with initalizing the checksum
.text:827ED4A0                 li      %r3, 0				# If not, return 0 (NOTE: r3 is always the return value)
.text:827ED4A4                 blr							# Return
.text:827ED4A8 ChecksumInit:
.text:827ED4A8                 addi    %r11, %r3, 1			# Remember r3 is a pointer, so we add one to the pointer and store it in r11
.text:827ED4AC                 lbz     %r9, 0(%r3)			# Load a byte at index 0 (same as r3[0]) into r9
.text:827ED4B0                 lbz     %r8, 1(%r3)			# Load another byte at index 1 into r8
.text:827ED4B4                 addic.  %r10, %r4, -4		# Add -4 to the data size (same as subtracting 4) and store in r10 then compare to zero
.text:827ED4B8                 addi    %r11, %r11, 1		# Increment r11
.text:827ED4BC                 rotrwi  %r9, %r9, 8			# Rotate the bits right by 8 bits in the lower word of register 9
.text:827ED4C0                 rotrwi  %r8, %r8, 16			# Rotate the bits right by 16 bits in the lower word of register 8
.text:827ED4C4                 or      %r8, %r8, %r9		# OR the two registers together and store in r8
.text:827ED4C8                 lbz     %r9, 0(%r11)			# Load a byte at index 3 (remeber r11 = r3 + 1) into r9
.text:827ED4CC                 addi    %r11, %r11, 1		# Increment the index once more
.text:827ED4D0                 rotlwi  %r7, %r9, 8			# Rotate r9 bits left by 8
.text:827ED4D4                 addi    %r9, %r11, 1			# store r11 + 1 in r9
.text:827ED4D8                 or      %r8, %r7, %r8		# OR r8 with r7 and store in r8
.text:827ED4DC                 lbz     %r11, 0(%r11)		# Load another byte
.text:827ED4E0                 or      %r11, %r11, %r8		# OR r11 with r8 and store in r11
.text:827ED4E4                 not     %r11, %r11			# Reverse all of the bits (~r11)
.text:827ED4E8                 beq     Finish				# If we hit the end and are out of bytes, end the fucntion
.text:827ED4EC                 lis     %r8, CrcTable@h		# Load the high half word of the CrcTable location into r8 then shift it by 16 bits. r8 = 00000000.82C40000
.text:827ED4F0                 addi    %r8, %r8, CrcTable@l # Add the low half word of the CrcTable location to r8. r8 = 00000000.82C45D80
.text:827ED4F4
.text:827ED4F4 ChecksumLoop:								# Let the checksum loop commence
.text:827ED4F4                 rlwinm  %r7, %r11, 10,22,29  # Rotate r11 left by 10 bits then AND with a bitmask with bits 22 - 29 set
.text:827ED4F8                 lbz     %r6, 0(%r9)			# Load another byte from the data (the pointer is in r9 now)
.text:827ED4FC                 slwi    %r11, %r11, 8		# Shift r11 by 8 and store in r11
.text:827ED500                 addic.  %r10, %r10, -1		# Add -1 to r10 (wich has the data size in it now) and compare to zero
.text:827ED504                 or      %r11, %r11, %r6		# OR r11 and r6 and store in r11
.text:827ED508                 addi    %r9, %r9, 1			# Incremenet r9 by 1
.text:827ED50C                 lwzx    %r7, %r7, %r8		# Load a word at memory address r7 + r8 (r8 has the CrcTable pointer in it) into r7
.text:827ED510                 xor     %r11, %r7, %r11		# XOR r7 with r11 and store in r11
.text:827ED514                 bne     ChecksumLoop			# If we have not hit the end of the data, continue, else finish
.text:827ED518
.text:827ED518 Finish:
.text:827ED518                 not     %r3, %r11			# Reverse the bits of r11 and store into r3 (r3 = ~r11)
.text:827ED51C                 blr							# Return the checksum
.text:827ED51C # End of function GenerateChecksum


.data:82C45D80 CrcTable:   .byte    0
.data:82C45D80
.data:82C45D81                 .byte    0
.data:82C45D82                 .byte    0
.data:82C45D83                 .byte    0
.data:82C45D84                 .byte    4
.data:82C45D85                 .byte 0xC
.data:82C45D86                 .byte 0x1D1 # -
.data:82C45D87                 .byte 0xB7 # +
.data:82C45D88                 .byte    9
.data:82C45D89                 .byte 0x82 # é
.data:82C45D8A                 .byte 0x3B # ;
.data:82C45D8B                 .byte 0x6E # n
.data:82C45D8C                 .byte  0xD
.data:82C45D8D                 .byte 0x43 # C
.data:82C45D8E                 .byte 0x26 # &
.data:82C45D8F                 .byte 0xD9 # +
.data:82C45D90                 .byte 0x13
.data:82C45D91                 .byte    4
.data:82C45D92                 .byte 0x76 # v
.data:82C45D93                 .byte 0xDC # _
.data:82C45D94                 .byte 0x17
.data:82C45D95                 .byte 0xC5 # +
.data:82C45D96                 .byte 0x6B # k
.data:82C45D97                 .byte 0x6B # k
.data:82C45D98                 .byte 0x1A
.data:82C45D99                 .byte 0x86 # å
.data:82C45D9A                 .byte 0x4D # M
.data:82C45D9B                 .byte 0xB2 # ¦
.data:82C45D9C                 .byte 0x1E
.data:82C45D9D                 .byte 0x47 # G
.data:82C45D9E                 .byte 0x50 # P
.data:82C45D9F                 .byte    5
.data:82C45DA0                 .byte 0x26 # &
.data:82C45DA1                 .byte    8
.data:82C45DA2                 .byte 0xED # f
.data:82C45DA3                 .byte 0xB8 # +
.data:82C45DA4                 .byte 0x22 # "
.data:82C45DA5                 .byte 0xC9 # +
.data:82C45DA6                 .byte 0xF0 # =
.data:82C45DA7                 .byte  0xF
.data:82C45DA8                 .byte 0x2F # /
.data:82C45DA9                 .byte 0x8A # è
.data:82C45DAA                 .byte 0xD6 # +
.data:82C45DAB                 .byte 0xD6 # +
.data:82C45DAC                 .byte 0x2B # +
.data:82C45DAD                 .byte 0x4B # K
.data:82C45DAE                 .byte 0xCB # -
.data:82C45DAF                 .byte 0x61 # a
.data:82C45DB0                 .byte 0x35 # 5
.data:82C45DB1                 .byte  0xC
.data:82C45DB2                 .byte 0x9B # ¢
.data:82C45DB3                 .byte 0x64 # d
.data:82C45DB4                 .byte 0x31 # 1
.data:82C45DB5                 .byte 0xCD # -
.data:82C45DB6                 .byte 0x86 # å
.data:82C45DB7                 .byte 0xD3 # +
.data:82C45DB8                 .byte 0x3C # <
.data:82C45DB9                 .byte 0x8E # Ä
.data:82C45DBA                 .byte 0xA0 # á
.data:82C45DBB                 .byte  0xA
.data:82C45DBC                 .byte 0x38 # 8
.data:82C45DBD                 .byte 0x4F # O
.data:82C45DBE                 .byte 0xBD # +
.data:82C45DBF                 .byte 0xBD # +
.data:82C45DC0                 .byte 0x4C # L
.data:82C45DC1                 .byte 0x11
.data:82C45DC2                 .byte 0xDB # ¦
.data:82C45DC3                 .byte 0x70 # p
.data:82C45DC4                 .byte 0x48 # H
.data:82C45DC5                 .byte 0xD0 # -
.data:82C45DC6                 .byte 0xC6 # ¦
.data:82C45DC7                 .byte 0xC7 # ¦
.data:82C45DC8                 .byte 0x45 # E
.data:82C45DC9                 .byte 0x93 # ô
.data:82C45DCA                 .byte 0xE0 # a
.data:82C45DCB                 .byte 0x1E
.data:82C45DCC                 .byte 0x41 # A
.data:82C45DCD                 .byte 0x52 # R
.data:82C45DCE                 .byte 0xFD # ²
.data:82C45DCF                 .byte 0xA9 # ¬
.data:82C45DD0                 .byte 0x5F # _
.data:82C45DD1                 .byte 0x15
.data:82C45DD2                 .byte 0xAD # ¡
.data:82C45DD3                 .byte 0xAC # ¼
.data:82C45DD4                 .byte 0x5B # [
.data:82C45DD5                 .byte 0xD4 # +
.data:82C45DD6                 .byte 0xB0 # ¦
.data:82C45DD7                 .byte 0x1B
.data:82C45DD8                 .byte 0x56 # V
.data:82C45DD9                 .byte 0x97 # ù
.data:82C45DDA                 .byte 0x96 # û
.data:82C45DDB                 .byte 0xC2 # -
.data:82C45DDC                 .byte 0x52 # R
.data:82C45DDD                 .byte 0x56 # V
.data:82C45DDE                 .byte 0x8B # ï
.data:82C45DDF                 .byte 0x75 # u
.data:82C45DE0                 .byte 0x6A # j
.data:82C45DE1                 .byte 0x19
.data:82C45DE2                 .byte 0x36 # 6
.data:82C45DE3                 .byte 0xC8 # +
.data:82C45DE4                 .byte 0x6E # n
.data:82C45DE5                 .byte 0xD8 # +
.data:82C45DE6                 .byte 0x2B # +
.data:82C45DE7                 .byte 0x7F # 
.data:82C45DE8                 .byte 0x63 # c
.data:82C45DE9                 .byte 0x9B # ¢
.data:82C45DEA                 .byte  0xD
.data:82C45DEB                 .byte 0xA6 # ª
.data:82C45DEC                 .byte 0x67 # g
.data:82C45DED                 .byte 0x5A # Z
.data:82C45DEE                 .byte 0x10
.data:82C45DEF                 .byte 0x11
.data:82C45DF0                 .byte 0x79 # y
.data:82C45DF1                 .byte 0x1D
.data:82C45DF2                 .byte 0x40 # @
.data:82C45DF3                 .byte 0x14
.data:82C45DF4                 .byte 0x7D # }
.data:82C45DF5                 .byte 0xDC # _
.data:82C45DF6                 .byte 0x5D # ]
.data:82C45DF7                 .byte 0xA3 # ú
.data:82C45DF8                 .byte 0x70 # p
.data:82C45DF9                 .byte 0x9F # ƒ
.data:82C45DFA                 .byte 0x7B # {
.data:82C45DFB                 .byte 0x7A # z
.data:82C45DFC                 .byte 0x74 # t
.data:82C45DFD                 .byte 0x5E # ^
.data:82C45DFE                 .byte 0x66 # f
.data:82C45DFF                 .byte 0xCD # -
.data:82C45E00                 .byte 0x98 # ÿ
.data:82C45E01                 .byte 0x23 # #
.data:82C45E02                 .byte 0xB6 # ¦
.data:82C45E03                 .byte 0xE0 # a
.data:82C45E04                 .byte 0x9C # £
.data:82C45E05                 .byte 0xE2 # G
.data:82C45E06                 .byte 0xAB # ½
.data:82C45E07                 .byte 0x57 # W
.data:82C45E08                 .byte 0x91 # æ
.data:82C45E09                 .byte 0xA1 # í
.data:82C45E0A                 .byte 0x8D # ì
.data:82C45E0B                 .byte 0x8E # Ä
.data:82C45E0C                 .byte 0x95 # ò
.data:82C45E0D                 .byte 0x60 # `
.data:82C45E0E                 .byte 0x90 # É
.data:82C45E0F                 .byte 0x39 # 9
.data:82C45E10                 .byte 0x8B # ï
.data:82C45E11                 .byte 0x27 # '
.data:82C45E12                 .byte 0xC0 # +
.data:82C45E13                 .byte 0x3C # <
.data:82C45E14                 .byte 0x8F # Å
.data:82C45E15                 .byte 0xE6 # µ
.data:82C45E16                 .byte 0xDD # ¦
.data:82C45E17                 .byte 0x8B # ï
.data:82C45E18                 .byte 0x82 # é
.data:82C45E19                 .byte 0xA5 # Ñ
.data:82C45E1A                 .byte 0xFB # v
.data:82C45E1B                 .byte 0x52 # R
.data:82C45E1C                 .byte 0x86 # å
.data:82C45E1D                 .byte 0x64 # d
.data:82C45E1E                 .byte 0xE6 # µ
.data:82C45E1F                 .byte 0xE5 # s
.data:82C45E20                 .byte 0xBE # +
.data:82C45E21                 .byte 0x2B # +
.data:82C45E22                 .byte 0x5B # [
.data:82C45E23                 .byte 0x58 # X
.data:82C45E24                 .byte 0xBA # ¦
.data:82C45E25                 .byte 0xEA # O
.data:82C45E26                 .byte 0x46 # F
.data:82C45E27                 .byte 0xEF # n
.data:82C45E28                 .byte 0xB7 # +
.data:82C45E29                 .byte 0xA9 # ¬
.data:82C45E2A                 .byte 0x60 # `
.data:82C45E2B                 .byte 0x36 # 6
.data:82C45E2C                 .byte 0xB3 # ¦
.data:82C45E2D                 .byte 0x68 # h
.data:82C45E2E                 .byte 0x7D # }
.data:82C45E2F                 .byte 0x81 # ü
.data:82C45E30                 .byte 0xAD # ¡
.data:82C45E31                 .byte 0x2F # /
.data:82C45E32                 .byte 0x2D # -
.data:82C45E33                 .byte 0x84 # ä
.data:82C45E34                 .byte 0xA9 # ¬
.data:82C45E35                 .byte 0xEE # e
.data:82C45E36                 .byte 0x30 # 0
.data:82C45E37                 .byte 0x33 # 3
.data:82C45E38                 .byte 0xA4 # ñ
.data:82C45E39                 .byte 0xAD # ¡
.data:82C45E3A                 .byte 0x16
.data:82C45E3B                 .byte 0xEA # O
.data:82C45E3C                 .byte 0xA0 # á
.data:82C45E3D                 .byte 0x6C # l
.data:82C45E3E                 .byte  0xB
.data:82C45E3F                 .byte 0x5D # ]
.data:82C45E40                 .byte 0xD4 # +
.data:82C45E41                 .byte 0x32 # 2
.data:82C45E42                 .byte 0x6D # m
.data:82C45E43                 .byte 0x90 # É
.data:82C45E44                 .byte 0xD0 # -
.data:82C45E45                 .byte 0xF3 # =
.data:82C45E46                 .byte 0x70 # p
.data:82C45E47                 .byte 0x27 # '
.data:82C45E48                 .byte 0xDD # ¦
.data:82C45E49                 .byte 0xB0 # ¦
.data:82C45E4A                 .byte 0x56 # V
.data:82C45E4B                 .byte 0xFE # ¦
.data:82C45E4C                 .byte 0xD9 # +
.data:82C45E4D                 .byte 0x71 # q
.data:82C45E4E                 .byte 0x4B # K
.data:82C45E4F                 .byte 0x49 # I
.data:82C45E50                 .byte 0xC7 # ¦
.data:82C45E51                 .byte 0x36 # 6
.data:82C45E52                 .byte 0x1B
.data:82C45E53                 .byte 0x4C # L
.data:82C45E54                 .byte 0xC3 # +
.data:82C45E55                 .byte 0xF7 # ˜
.data:82C45E56                 .byte    6
.data:82C45E57                 .byte 0xFB # v
.data:82C45E58                 .byte 0xCE # +
.data:82C45E59                 .byte 0xB4 # ¦
.data:82C45E5A                 .byte 0x20
.data:82C45E5B                 .byte 0x22 # "
.data:82C45E5C                 .byte 0xCA # -
.data:82C45E5D                 .byte 0x75 # u
.data:82C45E5E                 .byte 0x3D # =
.data:82C45E5F                 .byte 0x95 # ò
.data:82C45E60                 .byte 0xF2 # =
.data:82C45E61                 .byte 0x3A # :
.data:82C45E62                 .byte 0x80 # Ç
.data:82C45E63                 .byte 0x28 # (
.data:82C45E64                 .byte 0xF6 # ÷
.data:82C45E65                 .byte 0xFB # v
.data:82C45E66                 .byte 0x9D # ¥
.data:82C45E67                 .byte 0x9F # ƒ
.data:82C45E68                 .byte 0xFB # v
.data:82C45E69                 .byte 0xB8 # +
.data:82C45E6A                 .byte 0xBB # +
.data:82C45E6B                 .byte 0x46 # F
.data:82C45E6C                 .byte 0xFF
.data:82C45E6D                 .byte 0x79 # y
.data:82C45E6E                 .byte 0xA6 # ª
.data:82C45E6F                 .byte 0xF1 # ±
.data:82C45E70                 .byte 0xE1 # ß
.data:82C45E71                 .byte 0x3E # >
.data:82C45E72                 .byte 0xF6 # ÷
.data:82C45E73                 .byte 0xF4 # (
.data:82C45E74                 .byte 0xE5 # s
.data:82C45E75                 .byte 0xFF
.data:82C45E76                 .byte 0xEB # d
.data:82C45E77                 .byte 0x43 # C
.data:82C45E78                 .byte 0xE8 # F
.data:82C45E79                 .byte 0xBC # +
.data:82C45E7A                 .byte 0xCD # -
.data:82C45E7B                 .byte 0x9A # Ü
.data:82C45E7C                 .byte 0xEC # 8
.data:82C45E7D                 .byte 0x7D # }
.data:82C45E7E                 .byte 0xD0 # -
.data:82C45E7F                 .byte 0x2D # -
.data:82C45E80                 .byte 0x34 # 4
.data:82C45E81                 .byte 0x86 # å
.data:82C45E82                 .byte 0x70 # p
.data:82C45E83                 .byte 0x77 # w
.data:82C45E84                 .byte 0x30 # 0
.data:82C45E85                 .byte 0x47 # G
.data:82C45E86                 .byte 0x6D # m
.data:82C45E87                 .byte 0xC0 # +
.data:82C45E88                 .byte 0x3D # =
.data:82C45E89                 .byte    4
.data:82C45E8A                 .byte 0x4B # K
.data:82C45E8B                 .byte 0x19
.data:82C45E8C                 .byte 0x39 # 9
.data:82C45E8D                 .byte 0xC5 # +
.data:82C45E8E                 .byte 0x56 # V
.data:82C45E8F                 .byte 0xAE # «
.data:82C45E90                 .byte 0x27 # '
.data:82C45E91                 .byte 0x82 # é
.data:82C45E92                 .byte    6
.data:82C45E93                 .byte 0xAB # ½
.data:82C45E94                 .byte 0x23 # #
.data:82C45E95                 .byte 0x43 # C
.data:82C45E96                 .byte 0x1B
.data:82C45E97                 .byte 0x1C
.data:82C45E98                 .byte 0x2E # .
.data:82C45E99                 .byte    0
.data:82C45E9A                 .byte 0x3D # =
.data:82C45E9B                 .byte 0xC5 # +
.data:82C45E9C                 .byte 0x2A # *
.data:82C45E9D                 .byte 0xC1 # -
.data:82C45E9E                 .byte 0x20
.data:82C45E9F                 .byte 0x72 # r
.data:82C45EA0                 .byte 0x12
.data:82C45EA1                 .byte 0x8E # Ä
.data:82C45EA2                 .byte 0x9D # ¥
.data:82C45EA3                 .byte 0xCF # -
.data:82C45EA4                 .byte 0x16
.data:82C45EA5                 .byte 0x4F # O
.data:82C45EA6                 .byte 0x80 # Ç
.data:82C45EA7                 .byte 0x78 # x
.data:82C45EA8                 .byte 0x1B
.data:82C45EA9                 .byte  0xC
.data:82C45EAA                 .byte 0xA6 # ª
.data:82C45EAB                 .byte 0xA1 # í
.data:82C45EAC                 .byte 0x1F
.data:82C45EAD                 .byte 0xCD # -
.data:82C45EAE                 .byte 0xBB # +
.data:82C45EAF                 .byte 0x16
.data:82C45EB0                 .byte    1
.data:82C45EB1                 .byte 0x8A # è
.data:82C45EB2                 .byte 0xEB # d
.data:82C45EB3                 .byte 0x13
.data:82C45EB4                 .byte    5
.data:82C45EB5                 .byte 0x4B # K
.data:82C45EB6                 .byte 0xF6 # ÷
.data:82C45EB7                 .byte 0xA4 # ñ
.data:82C45EB8                 .byte    8
.data:82C45EB9                 .byte    8
.data:82C45EBA                 .byte 0xD0 # -
.data:82C45EBB                 .byte 0x7D # }
.data:82C45EBC                 .byte  0xC
.data:82C45EBD                 .byte 0xC9 # +
.data:82C45EBE                 .byte 0xCD # -
.data:82C45EBF                 .byte 0xCA # -
.data:82C45EC0                 .byte 0x78 # x
.data:82C45EC1                 .byte 0x97 # ù
.data:82C45EC2                 .byte 0xAB # ½
.data:82C45EC3                 .byte    7
.data:82C45EC4                 .byte 0x7C # |
.data:82C45EC5                 .byte 0x56 # V
.data:82C45EC6                 .byte 0xB6 # ¦
.data:82C45EC7                 .byte 0xB0 # ¦
.data:82C45EC8                 .byte 0x71 # q
.data:82C45EC9                 .byte 0x15
.data:82C45ECA                 .byte 0x90 # É
.data:82C45ECB                 .byte 0x69 # i
.data:82C45ECC                 .byte 0x75 # u
.data:82C45ECD                 .byte 0xD4 # +
.data:82C45ECE                 .byte 0x8D # ì
.data:82C45ECF                 .byte 0xDE # ¦
.data:82C45ED0                 .byte 0x6B # k
.data:82C45ED1                 .byte 0x93 # ô
.data:82C45ED2                 .byte 0xDD # ¦
.data:82C45ED3                 .byte 0xDB # ¦
.data:82C45ED4                 .byte 0x6F # o
.data:82C45ED5                 .byte 0x52 # R
.data:82C45ED6                 .byte 0xC0 # +
.data:82C45ED7                 .byte 0x6C # l
.data:82C45ED8                 .byte 0x62 # b
.data:82C45ED9                 .byte 0x11
.data:82C45EDA                 .byte 0xE6 # µ
.data:82C45EDB                 .byte 0xB5 # ¦
.data:82C45EDC                 .byte 0x66 # f
.data:82C45EDD                 .byte 0xD0 # -
.data:82C45EDE                 .byte 0xFB # v
.data:82C45EDF                 .byte    2
.data:82C45EE0                 .byte 0x5E # ^
.data:82C45EE1                 .byte 0x9F # ƒ
.data:82C45EE2                 .byte 0x46 # F
.data:82C45EE3                 .byte 0xBF # +
.data:82C45EE4                 .byte 0x5A # Z
.data:82C45EE5                 .byte 0x5E # ^
.data:82C45EE6                 .byte 0x5B # [
.data:82C45EE7                 .byte    8
.data:82C45EE8                 .byte 0x57 # W
.data:82C45EE9                 .byte 0x1D
.data:82C45EEA                 .byte 0x7D # }
.data:82C45EEB                 .byte 0xD1 # -
.data:82C45EEC                 .byte 0x53 # S
.data:82C45EED                 .byte 0xDC # _
.data:82C45EEE                 .byte 0x60 # `
.data:82C45EEF                 .byte 0x66 # f
.data:82C45EF0                 .byte 0x4D # M
.data:82C45EF1                 .byte 0x9B # ¢
.data:82C45EF2                 .byte 0x30 # 0
.data:82C45EF3                 .byte 0x63 # c
.data:82C45EF4                 .byte 0x49 # I
.data:82C45EF5                 .byte 0x5A # Z
.data:82C45EF6                 .byte 0x2D # -
.data:82C45EF7                 .byte 0xD4 # +
.data:82C45EF8                 .byte 0x44 # D
.data:82C45EF9                 .byte 0x19
.data:82C45EFA                 .byte  0xB
.data:82C45EFB                 .byte  0xD
.data:82C45EFC                 .byte 0x40 # @
.data:82C45EFD                 .byte 0xD8 # +
.data:82C45EFE                 .byte 0x16
.data:82C45EFF                 .byte 0xBA # ¦
.data:82C45F00                 .byte 0xAC # ¼
.data:82C45F01                 .byte 0xA5 # Ñ
.data:82C45F02                 .byte 0xC6 # ¦
.data:82C45F03                 .byte 0x97 # ù
.data:82C45F04                 .byte 0xA8 # ¿
.data:82C45F05                 .byte 0x64 # d
.data:82C45F06                 .byte 0xDB # ¦
.data:82C45F07                 .byte 0x20
.data:82C45F08                 .byte 0xA5 # Ñ
.data:82C45F09                 .byte 0x27 # '
.data:82C45F0A                 .byte 0xFD # ²
.data:82C45F0B                 .byte 0xF9 # ·
.data:82C45F0C                 .byte 0xA1 # í
.data:82C45F0D                 .byte 0xE6 # µ
.data:82C45F0E                 .byte 0xE0 # a
.data:82C45F0F                 .byte 0x4E # N
.data:82C45F10                 .byte 0xBF # +
.data:82C45F11                 .byte 0xA1 # í
.data:82C45F12                 .byte 0xB0 # ¦
.data:82C45F13                 .byte 0x4B # K
.data:82C45F14                 .byte 0xBB # +
.data:82C45F15                 .byte 0x60 # `
.data:82C45F16                 .byte 0xAD # ¡
.data:82C45F17                 .byte 0xFC # n
.data:82C45F18                 .byte 0xB6 # ¦
.data:82C45F19                 .byte 0x23 # #
.data:82C45F1A                 .byte 0x8B # ï
.data:82C45F1B                 .byte 0x25 # %
.data:82C45F1C                 .byte 0xB2 # ¦
.data:82C45F1D                 .byte 0xE2 # G
.data:82C45F1E                 .byte 0x96 # û
.data:82C45F1F                 .byte 0x92 # Æ
.data:82C45F20                 .byte 0x8A # è
.data:82C45F21                 .byte 0xAD # ¡
.data:82C45F22                 .byte 0x2B # +
.data:82C45F23                 .byte 0x2F # /
.data:82C45F24                 .byte 0x8E # Ä
.data:82C45F25                 .byte 0x6C # l
.data:82C45F26                 .byte 0x36 # 6
.data:82C45F27                 .byte 0x98 # ÿ
.data:82C45F28                 .byte 0x83 # â
.data:82C45F29                 .byte 0x2F # /
.data:82C45F2A                 .byte 0x10
.data:82C45F2B                 .byte 0x41 # A
.data:82C45F2C                 .byte 0x87 # ç
.data:82C45F2D                 .byte 0xEE # e
.data:82C45F2E                 .byte  0xD
.data:82C45F2F                 .byte 0xF6 # ÷
.data:82C45F30                 .byte 0x99 # Ö
.data:82C45F31                 .byte 0xA9 # ¬
.data:82C45F32                 .byte 0x5D # ]
.data:82C45F33                 .byte 0xF3 # =
.data:82C45F34                 .byte 0x9D # ¥
.data:82C45F35                 .byte 0x68 # h
.data:82C45F36                 .byte 0x40 # @
.data:82C45F37                 .byte 0x44 # D
.data:82C45F38                 .byte 0x90 # É
.data:82C45F39                 .byte 0x2B # +
.data:82C45F3A                 .byte 0x66 # f
.data:82C45F3B                 .byte 0x9D # ¥
.data:82C45F3C                 .byte 0x94 # ö
.data:82C45F3D                 .byte 0xEA # O
.data:82C45F3E                 .byte 0x7B # {
.data:82C45F3F                 .byte 0x2A # *
.data:82C45F40                 .byte 0xE0 # a
.data:82C45F41                 .byte 0xB4 # ¦
.data:82C45F42                 .byte 0x1D
.data:82C45F43                 .byte 0xE7 # t
.data:82C45F44                 .byte 0xE4 # S
.data:82C45F45                 .byte 0x75 # u
.data:82C45F46                 .byte    0
.data:82C45F47                 .byte 0x50 # P
.data:82C45F48                 .byte 0xE9 # T
.data:82C45F49                 .byte 0x36 # 6
.data:82C45F4A                 .byte 0x26 # &
.data:82C45F4B                 .byte 0x89 # ë
.data:82C45F4C                 .byte 0xED # f
.data:82C45F4D                 .byte 0xF7 # ˜
.data:82C45F4E                 .byte 0x3B # ;
.data:82C45F4F                 .byte 0x3E # >
.data:82C45F50                 .byte 0xF3 # =
.data:82C45F51                 .byte 0xB0 # ¦
.data:82C45F52                 .byte 0x6B # k
.data:82C45F53                 .byte 0x3B # ;
.data:82C45F54                 .byte 0xF7 # ˜
.data:82C45F55                 .byte 0x71 # q
.data:82C45F56                 .byte 0x76 # v
.data:82C45F57                 .byte 0x8C # î
.data:82C45F58                 .byte 0xFA # ·
.data:82C45F59                 .byte 0x32 # 2
.data:82C45F5A                 .byte 0x50 # P
.data:82C45F5B                 .byte 0x55 # U
.data:82C45F5C                 .byte 0xFE # ¦
.data:82C45F5D                 .byte 0xF3 # =
.data:82C45F5E                 .byte 0x4D # M
.data:82C45F5F                 .byte 0xE2 # G
.data:82C45F60                 .byte 0xC6 # ¦
.data:82C45F61                 .byte 0xBC # +
.data:82C45F62                 .byte 0xF0 # =
.data:82C45F63                 .byte 0x5F # _
.data:82C45F64                 .byte 0xC2 # -
.data:82C45F65                 .byte 0x7D # }
.data:82C45F66                 .byte 0xED # f
.data:82C45F67                 .byte 0xE8 # F
.data:82C45F68                 .byte 0xCF # -
.data:82C45F69                 .byte 0x3E # >
.data:82C45F6A                 .byte 0xCB # -
.data:82C45F6B                 .byte 0x31 # 1
.data:82C45F6C                 .byte 0xCB # -
.data:82C45F6D                 .byte 0xFF
.data:82C45F6E                 .byte 0xD6 # +
.data:82C45F6F                 .byte 0x86 # å
.data:82C45F70                 .byte 0xD5 # +
.data:82C45F71                 .byte 0xB8 # +
.data:82C45F72                 .byte 0x86 # å
.data:82C45F73                 .byte 0x83 # â
.data:82C45F74                 .byte 0xD1 # -
.data:82C45F75                 .byte 0x79 # y
.data:82C45F76                 .byte 0x9B # ¢
.data:82C45F77                 .byte 0x34 # 4
.data:82C45F78                 .byte 0xDC # _
.data:82C45F79                 .byte 0x3A # :
.data:82C45F7A                 .byte 0xBD # +
.data:82C45F7B                 .byte 0xED # f
.data:82C45F7C                 .byte 0xD8 # +
.data:82C45F7D                 .byte 0xFB # v
.data:82C45F7E                 .byte 0xA0 # á
.data:82C45F7F                 .byte 0x5A # Z
.data:82C45F80                 .byte 0x69 # i
.data:82C45F81                 .byte  0xC
.data:82C45F82                 .byte 0xE0 # a
.data:82C45F83                 .byte 0xEE # e
.data:82C45F84                 .byte 0x6D # m
.data:82C45F85                 .byte 0xCD # -
.data:82C45F86                 .byte 0xFD # ²
.data:82C45F87                 .byte 0x59 # Y
.data:82C45F88                 .byte 0x60 # `
.data:82C45F89                 .byte 0x8E # Ä
.data:82C45F8A                 .byte 0xDB # ¦
.data:82C45F8B                 .byte 0x80 # Ç
.data:82C45F8C                 .byte 0x64 # d
.data:82C45F8D                 .byte 0x4F # O
.data:82C45F8E                 .byte 0xC6 # ¦
.data:82C45F8F                 .byte 0x37 # 7
.data:82C45F90                 .byte 0x7A # z
.data:82C45F91                 .byte    8
.data:82C45F92                 .byte 0x96 # û
.data:82C45F93                 .byte 0x32 # 2
.data:82C45F94                 .byte 0x7E # ~
.data:82C45F95                 .byte 0xC9 # +
.data:82C45F96                 .byte 0x8B # ï
.data:82C45F97                 .byte 0x85 # à
.data:82C45F98                 .byte 0x73 # s
.data:82C45F99                 .byte 0x8A # è
.data:82C45F9A                 .byte 0xAD # ¡
.data:82C45F9B                 .byte 0x5C # \
.data:82C45F9C                 .byte 0x77 # w
.data:82C45F9D                 .byte 0x4B # K
.data:82C45F9E                 .byte 0xB0 # ¦
.data:82C45F9F                 .byte 0xEB # d
.data:82C45FA0                 .byte 0x4F # O
.data:82C45FA1                 .byte    4
.data:82C45FA2                 .byte  0xD
.data:82C45FA3                 .byte 0x56 # V
.data:82C45FA4                 .byte 0x4B # K
.data:82C45FA5                 .byte 0xC5 # +
.data:82C45FA6                 .byte 0x10
.data:82C45FA7                 .byte 0xE1 # ß
.data:82C45FA8                 .byte 0x46 # F
.data:82C45FA9                 .byte 0x86 # å
.data:82C45FAA                 .byte 0x36 # 6
.data:82C45FAB                 .byte 0x38 # 8
.data:82C45FAC                 .byte 0x42 # B
.data:82C45FAD                 .byte 0x47 # G
.data:82C45FAE                 .byte 0x2B # +
.data:82C45FAF                 .byte 0x8F # Å
.data:82C45FB0                 .byte 0x5C # \
.data:82C45FB1                 .byte    0
.data:82C45FB2                 .byte 0x7B # {
.data:82C45FB3                 .byte 0x8A # è
.data:82C45FB4                 .byte 0x58 # X
.data:82C45FB5                 .byte 0xC1 # -
.data:82C45FB6                 .byte 0x66 # f
.data:82C45FB7                 .byte 0x3D # =
.data:82C45FB8                 .byte 0x55 # U
.data:82C45FB9                 .byte 0x82 # é
.data:82C45FBA                 .byte 0x40 # @
.data:82C45FBB                 .byte 0xE4 # S
.data:82C45FBC                 .byte 0x51 # Q
.data:82C45FBD                 .byte 0x43 # C
.data:82C45FBE                 .byte 0x5D # ]
.data:82C45FBF                 .byte 0x53 # S
.data:82C45FC0                 .byte 0x25 # %
.data:82C45FC1                 .byte 0x1D
.data:82C45FC2                 .byte 0x3B # ;
.data:82C45FC3                 .byte 0x9E # P
.data:82C45FC4                 .byte 0x21 # !
.data:82C45FC5                 .byte 0xDC # _
.data:82C45FC6                 .byte 0x26 # &
.data:82C45FC7                 .byte 0x29 # )
.data:82C45FC8                 .byte 0x2C # ,
.data:82C45FC9                 .byte 0x9F # ƒ
.data:82C45FCA                 .byte    0
.data:82C45FCB                 .byte 0xF0 # =
.data:82C45FCC                 .byte 0x28 # (
.data:82C45FCD                 .byte 0x5E # ^
.data:82C45FCE                 .byte 0x1D
.data:82C45FCF                 .byte 0x47 # G
.data:82C45FD0                 .byte 0x36 # 6
.data:82C45FD1                 .byte 0x19
.data:82C45FD2                 .byte 0x4D # M
.data:82C45FD3                 .byte 0x42 # B
.data:82C45FD4                 .byte 0x32 # 2
.data:82C45FD5                 .byte 0xD8 # +
.data:82C45FD6                 .byte 0x50 # P
.data:82C45FD7                 .byte 0xF5 # )
.data:82C45FD8                 .byte 0x3F # ?
.data:82C45FD9                 .byte 0x9B # ¢
.data:82C45FDA                 .byte 0x76 # v
.data:82C45FDB                 .byte 0x2C # ,
.data:82C45FDC                 .byte 0x3B # ;
.data:82C45FDD                 .byte 0x5A # Z
.data:82C45FDE                 .byte 0x6B # k
.data:82C45FDF                 .byte 0x9B # ¢
.data:82C45FE0                 .byte    3
.data:82C45FE1                 .byte 0x15
.data:82C45FE2                 .byte 0xD6 # +
.data:82C45FE3                 .byte 0x26 # &
.data:82C45FE4                 .byte    7
.data:82C45FE5                 .byte 0xD4 # +
.data:82C45FE6                 .byte 0xCB # -
.data:82C45FE7                 .byte 0x91 # æ
.data:82C45FE8                 .byte  0xA
.data:82C45FE9                 .byte 0x97 # ù
.data:82C45FEA                 .byte 0xED # f
.data:82C45FEB                 .byte 0x48 # H
.data:82C45FEC                 .byte  0xE
.data:82C45FED                 .byte 0x56 # V
.data:82C45FEE                 .byte 0xF0 # =
.data:82C45FEF                 .byte 0xFF
.data:82C45FF0                 .byte 0x10
.data:82C45FF1                 .byte 0x11
.data:82C45FF2                 .byte 0xA0 # á
.data:82C45FF3                 .byte 0xFA # ·
.data:82C45FF4                 .byte 0x14
.data:82C45FF5                 .byte 0xD0 # -
.data:82C45FF6                 .byte 0xBD # +
.data:82C45FF7                 .byte 0x4D # M
.data:82C45FF8                 .byte 0x19
.data:82C45FF9                 .byte 0x93 # ô
.data:82C45FFA                 .byte 0x9B # ¢
.data:82C45FFB                 .byte 0x94 # ö
.data:82C45FFC                 .byte 0x1D
.data:82C45FFD                 .byte 0x52 # R
.data:82C45FFE                 .byte 0x86 # å
.data:82C45FFF                 .byte 0x23 # #
.data:82C46000                 .byte 0xF1 # ±
.data:82C46001                 .byte 0x2F # /
.data:82C46002                 .byte 0x56 # V
.data:82C46003                 .byte  0xE
.data:82C46004                 .byte 0xF5 # )
.data:82C46005                 .byte 0xEE # e
.data:82C46006                 .byte 0x4B # K
.data:82C46007                 .byte 0xB9 # ¦
.data:82C46008                 .byte 0xF8 # °
.data:82C46009                 .byte 0xAD # ¡
.data:82C4600A                 .byte 0x6D # m
.data:82C4600B                 .byte 0x60 # `
.data:82C4600C                 .byte 0xFC # n
.data:82C4600D                 .byte 0x6C # l
.data:82C4600E                 .byte 0x70 # p
.data:82C4600F                 .byte 0xD7 # +
.data:82C46010                 .byte 0xE2 # G
.data:82C46011                 .byte 0x2B # +
.data:82C46012                 .byte 0x20
.data:82C46013                 .byte 0xD2 # -
.data:82C46014                 .byte 0xE6 # µ
.data:82C46015                 .byte 0xEA # O
.data:82C46016                 .byte 0x3D # =
.data:82C46017                 .byte 0x65 # e
.data:82C46018                 .byte 0xEB # d
.data:82C46019                 .byte 0xA9 # ¬
.data:82C4601A                 .byte 0x1B
.data:82C4601B                 .byte 0xBC # +
.data:82C4601C                 .byte 0xEF # n
.data:82C4601D                 .byte 0x68 # h
.data:82C4601E                 .byte    6
.data:82C4601F                 .byte  0xB
.data:82C46020                 .byte 0xD7 # +
.data:82C46021                 .byte 0x27 # '
.data:82C46022                 .byte 0xBB # +
.data:82C46023                 .byte 0xB6 # ¦
.data:82C46024                 .byte 0xD3 # +
.data:82C46025                 .byte 0xE6 # µ
.data:82C46026                 .byte 0xA6 # ª
.data:82C46027                 .byte    1
.data:82C46028                 .byte 0xDE # ¦
.data:82C46029                 .byte 0xA5 # Ñ
.data:82C4602A                 .byte 0x80 # Ç
.data:82C4602B                 .byte 0xD8 # +
.data:82C4602C                 .byte 0xDA # +
.data:82C4602D                 .byte 0x64 # d
.data:82C4602E                 .byte 0x9D # ¥
.data:82C4602F                 .byte 0x6F # o
.data:82C46030                 .byte 0xC4 # -
.data:82C46031                 .byte 0x23 # #
.data:82C46032                 .byte 0xCD # -
.data:82C46033                 .byte 0x6A # j
.data:82C46034                 .byte 0xC0 # +
.data:82C46035                 .byte 0xE2 # G
.data:82C46036                 .byte 0xD0 # -
.data:82C46037                 .byte 0xDD # ¦
.data:82C46038                 .byte 0xCD # -
.data:82C46039                 .byte 0xA1 # í
.data:82C4603A                 .byte 0xF6 # ÷
.data:82C4603B                 .byte    4
.data:82C4603C                 .byte 0xC9 # +
.data:82C4603D                 .byte 0x60 # `
.data:82C4603E                 .byte 0xEB # d
.data:82C4603F                 .byte 0xB3 # ¦
.data:82C46040                 .byte 0xBD # +
.data:82C46041                 .byte 0x3E # >
.data:82C46042                 .byte 0x8D # ì
.data:82C46043                 .byte 0x7E # ~
.data:82C46044                 .byte 0xB9 # ¦
.data:82C46045                 .byte 0xFF
.data:82C46046                 .byte 0x90 # É
.data:82C46047                 .byte 0xC9 # +
.data:82C46048                 .byte 0xB4 # ¦
.data:82C46049                 .byte 0xBC # +
.data:82C4604A                 .byte 0xB6 # ¦
.data:82C4604B                 .byte 0x10
.data:82C4604C                 .byte 0xB0 # ¦
.data:82C4604D                 .byte 0x7D # }
.data:82C4604E                 .byte 0xAB # ½
.data:82C4604F                 .byte 0xA7 # º
.data:82C46050                 .byte 0xAE # «
.data:82C46051                 .byte 0x3A # :
.data:82C46052                 .byte 0xFB # v
.data:82C46053                 .byte 0xA2 # ó
.data:82C46054                 .byte 0xAA # ¬
.data:82C46055                 .byte 0xFB # v
.data:82C46056                 .byte 0xE6 # µ
.data:82C46057                 .byte 0x15
.data:82C46058                 .byte 0xA7 # º
.data:82C46059                 .byte 0xB8 # +
.data:82C4605A                 .byte 0xC0 # +
.data:82C4605B                 .byte 0xCC # ¦
.data:82C4605C                 .byte 0xA3 # ú
.data:82C4605D                 .byte 0x79 # y
.data:82C4605E                 .byte 0xDD # ¦
.data:82C4605F                 .byte 0x7B # {
.data:82C46060                 .byte 0x9B # ¢
.data:82C46061                 .byte 0x36 # 6
.data:82C46062                 .byte 0x60 # `
.data:82C46063                 .byte 0xC6 # ¦
.data:82C46064                 .byte 0x9F # ƒ
.data:82C46065                 .byte 0xF7 # ˜
.data:82C46066                 .byte 0x7D # }
.data:82C46067                 .byte 0x71 # q
.data:82C46068                 .byte 0x92 # Æ
.data:82C46069                 .byte 0xB4 # ¦
.data:82C4606A                 .byte 0x5B # [
.data:82C4606B                 .byte 0xA8 # ¿
.data:82C4606C                 .byte 0x96 # û
.data:82C4606D                 .byte 0x75 # u
.data:82C4606E                 .byte 0x46 # F
.data:82C4606F                 .byte 0x1F
.data:82C46070                 .byte 0x88 # ê
.data:82C46071                 .byte 0x32 # 2
.data:82C46072                 .byte 0x16
.data:82C46073                 .byte 0x1A
.data:82C46074                 .byte 0x8C # î
.data:82C46075                 .byte 0xF3 # =
.data:82C46076                 .byte  0xB
.data:82C46077                 .byte 0xAD # ¡
.data:82C46078                 .byte 0x81 # ü
.data:82C46079                 .byte 0xB0 # ¦
.data:82C4607A                 .byte 0x2D # -
.data:82C4607B                 .byte 0x74 # t
.data:82C4607C                 .byte 0x85 # à
.data:82C4607D                 .byte 0x71 # q
.data:82C4607E                 .byte 0x30 # 0
.data:82C4607F                 .byte 0xC3 # +
.data:82C46080                 .byte 0x5D # ]
.data:82C46081                 .byte 0x8A # è
.data:82C46082                 .byte 0x90 # É
.data:82C46083                 .byte 0x99 # Ö
.data:82C46084                 .byte 0x59 # Y
.data:82C46085                 .byte 0x4B # K
.data:82C46086                 .byte 0x8D # ì
.data:82C46087                 .byte 0x2E # .
.data:82C46088                 .byte 0x54 # T
.data:82C46089                 .byte    8
.data:82C4608A                 .byte 0xAB # ½
.data:82C4608B                 .byte 0xF7 # ˜
.data:82C4608C                 .byte 0x50 # P
.data:82C4608D                 .byte 0xC9 # +
.data:82C4608E                 .byte 0xB6 # ¦
.data:82C4608F                 .byte 0x40 # @
.data:82C46090                 .byte 0x4E # N
.data:82C46091                 .byte 0x8E # Ä
.data:82C46092                 .byte 0xE6 # µ
.data:82C46093                 .byte 0x45 # E
.data:82C46094                 .byte 0x4A # J
.data:82C46095                 .byte 0x4F # O
.data:82C46096                 .byte 0xFB # v
.data:82C46097                 .byte 0xF2 # =
.data:82C46098                 .byte 0x47 # G
.data:82C46099                 .byte  0xC
.data:82C4609A                 .byte 0xDD # ¦
.data:82C4609B                 .byte 0x2B # +
.data:82C4609C                 .byte 0x43 # C
.data:82C4609D                 .byte 0xCD # -
.data:82C4609E                 .byte 0xC0 # +
.data:82C4609F                 .byte 0x9C # £
.data:82C460A0                 .byte 0x7B # {
.data:82C460A1                 .byte 0x82 # é
.data:82C460A2                 .byte 0x7D # }
.data:82C460A3                 .byte 0x21 # !
.data:82C460A4                 .byte 0x7F # 
.data:82C460A5                 .byte 0x43 # C
.data:82C460A6                 .byte 0x60 # `
.data:82C460A7                 .byte 0x96 # û
.data:82C460A8                 .byte 0x72 # r
.data:82C460A9                 .byte    0
.data:82C460AA                 .byte 0x46 # F
.data:82C460AB                 .byte 0x4F # O
.data:82C460AC                 .byte 0x76 # v
.data:82C460AD                 .byte 0xC1 # -
.data:82C460AE                 .byte 0x5B # [
.data:82C460AF                 .byte 0xF8 # °
.data:82C460B0                 .byte 0x68 # h
.data:82C460B1                 .byte 0x86 # å
.data:82C460B2                 .byte  0xB
.data:82C460B3                 .byte 0xFD # ²
.data:82C460B4                 .byte 0x6C # l
.data:82C460B5                 .byte 0x47 # G
.data:82C460B6                 .byte 0x16
.data:82C460B7                 .byte 0x4A # J
.data:82C460B8                 .byte 0x61 # a
.data:82C460B9                 .byte    4
.data:82C460BA                 .byte 0x30 # 0
.data:82C460BB                 .byte 0x93 # ô
.data:82C460BC                 .byte 0x65 # e
.data:82C460BD                 .byte 0xC5 # +
.data:82C460BE                 .byte 0x2D # -
.data:82C460BF                 .byte 0x24 # $
.data:82C460C0                 .byte 0x11
.data:82C460C1                 .byte 0x9B # ¢
.data:82C460C2                 .byte 0x4B # K
.data:82C460C3                 .byte 0xE9 # T
.data:82C460C4                 .byte 0x15
.data:82C460C5                 .byte 0x5A # Z
.data:82C460C6                 .byte 0x56 # V
.data:82C460C7                 .byte 0x5E # ^
.data:82C460C8                 .byte 0x18
.data:82C460C9                 .byte 0x19
.data:82C460CA                 .byte 0x70 # p
.data:82C460CB                 .byte 0x87 # ç
.data:82C460CC                 .byte 0x1C
.data:82C460CD                 .byte 0xD8 # +
.data:82C460CE                 .byte 0x6D # m
.data:82C460CF                 .byte 0x30 # 0
.data:82C460D0                 .byte    2
.data:82C460D1                 .byte 0x9F # ƒ
.data:82C460D2                 .byte 0x3D # =
.data:82C460D3                 .byte 0x35 # 5
.data:82C460D4                 .byte    6
.data:82C460D5                 .byte 0x5E # ^
.data:82C460D6                 .byte 0x20
.data:82C460D7                 .byte 0x82 # é
.data:82C460D8                 .byte  0xB
.data:82C460D9                 .byte 0x1D
.data:82C460DA                 .byte    6
.data:82C460DB                 .byte 0x5B # [
.data:82C460DC                 .byte  0xF
.data:82C460DD                 .byte 0xDC # _
.data:82C460DE                 .byte 0x1B
.data:82C460DF                 .byte 0xEC # 8
.data:82C460E0                 .byte 0x37 # 7
.data:82C460E1                 .byte 0x93 # ô
.data:82C460E2                 .byte 0xA6 # ª
.data:82C460E3                 .byte 0x51 # Q
.data:82C460E4                 .byte 0x33 # 3
.data:82C460E5                 .byte 0x52 # R
.data:82C460E6                 .byte 0xBB # +
.data:82C460E7                 .byte 0xE6 # µ
.data:82C460E8                 .byte 0x3E # >
.data:82C460E9                 .byte 0x11
.data:82C460EA                 .byte 0x9D # ¥
.data:82C460EB                 .byte 0x3F # ?
.data:82C460EC                 .byte 0x3A # :
.data:82C460ED                 .byte 0xD0 # -
.data:82C460EE                 .byte 0x80 # Ç
.data:82C460EF                 .byte 0x88 # ê
.data:82C460F0                 .byte 0x24 # $
.data:82C460F1                 .byte 0x97 # ù
.data:82C460F2                 .byte 0xD0 # -
.data:82C460F3                 .byte 0x8D # ì
.data:82C460F4                 .byte 0x20
.data:82C460F5                 .byte 0x56 # V
.data:82C460F6                 .byte 0xCD # -
.data:82C460F7                 .byte 0x3A # :
.data:82C460F8                 .byte 0x2D # -
.data:82C460F9                 .byte 0x15
.data:82C460FA                 .byte 0xEB # d
.data:82C460FB                 .byte 0xE3 # p
.data:82C460FC                 .byte 0x29 # )
.data:82C460FD                 .byte 0xD4 # +
.data:82C460FE                 .byte 0xF6 # ÷
.data:82C460FF                 .byte 0x54 # T
.data:82C46100                 .byte 0xC5 # +
.data:82C46101                 .byte 0xA9 # ¬
.data:82C46102                 .byte 0x26 # &
.data:82C46103                 .byte 0x79 # y
.data:82C46104                 .byte 0xC1 # -
.data:82C46105                 .byte 0x68 # h
.data:82C46106                 .byte 0x3B # ;
.data:82C46107                 .byte 0xCE # +
.data:82C46108                 .byte 0xCC # ¦
.data:82C46109                 .byte 0x2B # +
.data:82C4610A                 .byte 0x1D
.data:82C4610B                 .byte 0x17
.data:82C4610C                 .byte 0xC8 # +
.data:82C4610D                 .byte 0xEA # O
.data:82C4610E                 .byte    0
.data:82C4610F                 .byte 0xA0 # á
.data:82C46110                 .byte 0xD6 # +
.data:82C46111                 .byte 0xAD # ¡
.data:82C46112                 .byte 0x50 # P
.data:82C46113                 .byte 0xA5 # Ñ
.data:82C46114                 .byte 0xD2 # -
.data:82C46115                 .byte 0x6C # l
.data:82C46116                 .byte 0x4D # M
.data:82C46117                 .byte 0x12
.data:82C46118                 .byte 0xDF # ¯
.data:82C46119                 .byte 0x2F # /
.data:82C4611A                 .byte 0x6B # k
.data:82C4611B                 .byte 0xCB # -
.data:82C4611C                 .byte 0xDB # ¦
.data:82C4611D                 .byte 0xEE # e
.data:82C4611E                 .byte 0x76 # v
.data:82C4611F                 .byte 0x7C # |
.data:82C46120                 .byte 0xE3 # p
.data:82C46121                 .byte 0xA1 # í
.data:82C46122                 .byte 0xCB # -
.data:82C46123                 .byte 0xC1 # -
.data:82C46124                 .byte 0xE7 # t
.data:82C46125                 .byte 0x60 # `
.data:82C46126                 .byte 0xD6 # +
.data:82C46127                 .byte 0x76 # v
.data:82C46128                 .byte 0xEA # O
.data:82C46129                 .byte 0x23 # #
.data:82C4612A                 .byte 0xF0 # =
.data:82C4612B                 .byte 0xAF # »
.data:82C4612C                 .byte 0xEE # e
.data:82C4612D                 .byte 0xE2 # G
.data:82C4612E                 .byte 0xED # f
.data:82C4612F                 .byte 0x18
.data:82C46130                 .byte 0xF0 # =
.data:82C46131                 .byte 0xA5 # Ñ
.data:82C46132                 .byte 0xBD # +
.data:82C46133                 .byte 0x1D
.data:82C46134                 .byte 0xF4 # (
.data:82C46135                 .byte 0x64 # d
.data:82C46136                 .byte 0xA0 # á
.data:82C46137                 .byte 0xAA # ¬
.data:82C46138                 .byte 0xF9 # ·
.data:82C46139                 .byte 0x27 # '
.data:82C4613A                 .byte 0x86 # å
.data:82C4613B                 .byte 0x73 # s
.data:82C4613C                 .byte 0xFD # ²
.data:82C4613D                 .byte 0xE6 # µ
.data:82C4613E                 .byte 0x9B # ¢
.data:82C4613F                 .byte 0xC4 # -
.data:82C46140                 .byte 0x89 # ë
.data:82C46141                 .byte 0xB8 # +
.data:82C46142                 .byte 0xFD # ²
.data:82C46143                 .byte    9
.data:82C46144                 .byte 0x8D # ì
.data:82C46145                 .byte 0x79 # y
.data:82C46146                 .byte 0xE0 # a
.data:82C46147                 .byte 0xBE # +
.data:82C46148                 .byte 0x80 # Ç
.data:82C46149                 .byte 0x3A # :
.data:82C4614A                 .byte 0xC6 # ¦
.data:82C4614B                 .byte 0x67 # g
.data:82C4614C                 .byte 0x84 # ä
.data:82C4614D                 .byte 0xFB # v
.data:82C4614E                 .byte 0xDB # ¦
.data:82C4614F                 .byte 0xD0 # -
.data:82C46150                 .byte 0x9A # Ü
.data:82C46151                 .byte 0xBC # +
.data:82C46152                 .byte 0x8B # ï
.data:82C46153                 .byte 0xD5 # +
.data:82C46154                 .byte 0x9E # P
.data:82C46155                 .byte 0x7D # }
.data:82C46156                 .byte 0x96 # û
.data:82C46157                 .byte 0x62 # b
.data:82C46158                 .byte 0x93 # ô
.data:82C46159                 .byte 0x3E # >
.data:82C4615A                 .byte 0xB0 # ¦
.data:82C4615B                 .byte 0xBB # +
.data:82C4615C                 .byte 0x97 # ù
.data:82C4615D                 .byte 0xFF
.data:82C4615E                 .byte 0xAD # ¡
.data:82C4615F                 .byte  0xC
.data:82C46160                 .byte 0xAF # »
.data:82C46161                 .byte 0xB0 # ¦
.data:82C46162                 .byte 0x10
.data:82C46163                 .byte 0xB1 # ¦
.data:82C46164                 .byte 0xAB # ½
.data:82C46165                 .byte 0x71 # q
.data:82C46166                 .byte  0xD
.data:82C46167                 .byte    6
.data:82C46168                 .byte 0xA6 # ª
.data:82C46169                 .byte 0x32 # 2
.data:82C4616A                 .byte 0x2B # +
.data:82C4616B                 .byte 0xDF # ¯
.data:82C4616C                 .byte 0xA2 # ó
.data:82C4616D                 .byte 0xF3 # =
.data:82C4616E                 .byte 0x36 # 6
.data:82C4616F                 .byte 0x68 # h
.data:82C46170                 .byte 0xBC # +
.data:82C46171                 .byte 0xB4 # ¦
.data:82C46172                 .byte 0x66 # f
.data:82C46173                 .byte 0x6D # m
.data:82C46174                 .byte 0xB8 # +
.data:82C46175                 .byte 0x75 # u
.data:82C46176                 .byte 0x7B # {
.data:82C46177                 .byte 0xDA # +
.data:82C46178                 .byte 0xB5 # ¦
.data:82C46179                 .byte 0x36 # 6
.data:82C4617A                 .byte 0x5D # ]
.data:82C4617B                 .byte    3
.data:82C4617C                 .byte 0xB1 # ¦
.data:82C4617D                 .byte 0xF7 # ˜
.data:82C4617E                 .byte 0x40 # @
.data:82C4617F                 .byte 0xB4 # ¦
.data:82C46180                 .byte 0x82 # é
.data:82C46181                 .byte    6
.data:82C46182                 .byte 0x37 # 7
.data:82C46183                 .byte 0x94 # ö
.data:82C46184                 .byte 0x82 # é
.data:82C46185                 .byte    6
.data:82C46186                 .byte 0x38 # 8
.data:82C46187                 .byte 0x94 # ö
.data:82C46188                 .byte 0x82 # é
.data:82C46189                 .byte    6
.data:82C4618A                 .byte 0x38 # 8
.data:82C4618B                 .byte 0xB0 # ¦
.data:82C4618C                 .byte 0x82 # é
.data:82C4618D                 .byte    6
.data:82C4618E                 .byte 0x38 # 8
.data:82C4618F                 .byte 0xD8 # +
.data:82C46190                 .byte 0x82 # é
.data:82C46191                 .byte    6
.data:82C46192                 .byte 0x38 # 8
.data:82C46193                 .byte 0xE4 # S
.data:82C46194                 .byte 0x82 # é
.data:82C46195                 .byte    6
.data:82C46196                 .byte 0x38 # 8
.data:82C46197                 .byte 0xF0 # =
.data:82C46198                 .byte 0x82 # é
.data:82C46199                 .byte    6
.data:82C4619A                 .byte 0x39 # 9
.data:82C4619B                 .byte    0
.data:82C4619C                 .byte 0x82 # é
.data:82C4619D                 .byte    6
.data:82C4619E                 .byte 0x3A # :
.data:82C4619F                 .byte 0x84 # ä
.data:82C461A0                 .byte 0x82 # é
.data:82C461A1                 .byte    6
.data:82C461A2                 .byte 0x3A # :
.data:82C461A3                 .byte 0x94 # ö