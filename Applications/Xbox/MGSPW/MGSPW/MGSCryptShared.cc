#include "stdafx.h"
#include "MGSCryptShared.h"

unsigned char obf_table[1024] = {
	0x50, 0xB8, 0x57, 0x61, 0x27, 0xBF, 0x67, 0xF7, 0xBE, 0xB6, 0x36, 0x4D,
	0xC9, 0xB1, 0x06, 0xDB, 0x57, 0xD5, 0x93, 0x78, 0x20, 0xD2, 0xA3, 0xEE,
	0xB9, 0xDB, 0xF2, 0x54, 0xCE, 0xDC, 0xC2, 0xC2, 0x5E, 0x63, 0xDF, 0x53,
	0x29, 0x64, 0xEF, 0xC5, 0xB0, 0x6D, 0xBE, 0x7F, 0xC7, 0x6A, 0x8E, 0xE9,
	0x59, 0x0E, 0x1B, 0x4A, 0x2E, 0x09, 0x2B, 0xDC, 0xB7, 0x00, 0x7A, 0x66,
	0xC0, 0x07, 0x4A, 0xF0, 0x4D, 0x0F, 0x47, 0x05, 0x3A, 0x08, 0x77, 0x93,
	0xA3, 0x01, 0x26, 0x29, 0xD4, 0x06, 0x16, 0xBF, 0x4A, 0x62, 0x83, 0x1C,
	0x3D, 0x65, 0xB3, 0x8A, 0xA4, 0x6C, 0xE2, 0x30, 0xD3, 0x6B, 0xD2, 0xA6,
	0x43, 0xD4, 0xCF, 0x37, 0x34, 0xD3, 0xFF, 0xA1, 0xAD, 0xDA, 0xAE, 0x1B,
	0xDA, 0xDD, 0x9E, 0x8D, 0x44, 0xB9, 0x0B, 0x2E, 0x33, 0xBE, 0x3B, 0xB8,
	0xAA, 0xB7, 0x6A, 0x02, 0xDD, 0xB0, 0x5A, 0x94, 0x6B, 0xD6, 0x77, 0xA9,
	0x1C, 0xD1, 0x47, 0x3F, 0x85, 0xD8, 0x16, 0x85, 0xF2, 0xDF, 0x26, 0x13,
	0x6C, 0xBB, 0xB3, 0xB0, 0x1B, 0xBC, 0x83, 0x26, 0x82, 0xB5, 0xD2, 0x9C,
	0xF5, 0xB2, 0xE2, 0x0A, 0x65, 0x0D, 0xFF, 0x9B, 0x12, 0x0A, 0xCF, 0x0D,
	0x8B, 0x03, 0x9E, 0xB7, 0xFC, 0x04, 0xAE, 0x21, 0x62, 0x60, 0x3B, 0x82,
	0x15, 0x67, 0x0B, 0x14, 0x8C, 0x6E, 0x5A, 0xAE, 0xFB, 0x69, 0x6A, 0x38,
	0x76, 0x61, 0x67, 0xCD, 0x01, 0x66, 0x57, 0x5B, 0x98, 0x6F, 0x06, 0xE1,
	0xEF, 0x68, 0x36, 0x77, 0x71, 0x0C, 0xA3, 0xD4, 0x06, 0x0B, 0x93, 0x42,
	0x9F, 0x02, 0xC2, 0xF8, 0xE8, 0x05, 0xF2, 0x6E, 0x78, 0xBA, 0xEF, 0xFF,
	0x0F, 0xBD, 0xDF, 0x69, 0x96, 0xB4, 0x8E, 0xD3, 0xE1, 0xB3, 0xBE, 0x45,
	0x7F, 0xD7, 0x2B, 0xE6, 0x08, 0xD0, 0x1B, 0x70, 0x91, 0xD9, 0x4A, 0xCA,
	0xE6, 0xDE, 0x7A, 0x5C, 0x26, 0x64, 0x16, 0xF1, 0x51, 0x63, 0x26, 0x67,
	0xC8, 0x6A, 0x77, 0xDD, 0xBF, 0x6D, 0x47, 0x4B, 0x21, 0x09, 0xD2, 0xE8,
	0x56, 0x0E, 0xE2, 0x7E, 0xCF, 0x07, 0xB3, 0xC4, 0xB8, 0x00, 0x83, 0x52,
	0x28, 0xBF, 0x9E, 0xC3, 0x5F, 0xB8, 0xAE, 0x55, 0xC6, 0xB1, 0xFF, 0xEF,
	0xB1, 0xB6, 0xCF, 0x79, 0x2F, 0xD2, 0x5A, 0xDA, 0x58, 0xD5, 0x6A, 0x4C,
	0xC1, 0xDC, 0x3B, 0xF6, 0xB6, 0xDB, 0x0B, 0x60, 0x3B, 0xD3, 0x06, 0x95,
	0x4C, 0xD4, 0x36, 0x03, 0xD5, 0xDD, 0x67, 0xB9, 0xA2, 0xDA, 0x57, 0x2F,
	0x3C, 0xBE, 0xC2, 0x8C, 0x4B, 0xB9, 0xF2, 0x1A, 0xD2, 0xB0, 0xA3, 0xA0,
	0xA5, 0xB7, 0x93, 0x36, 0x35, 0x08, 0x8E, 0xA7, 0x42, 0x0F, 0xBE, 0x31,
	0xDB, 0x06, 0xEF, 0x8B, 0xAC, 0x01, 0xDF, 0x1D, 0x32, 0x65, 0x4A, 0xBE,
	0x45, 0x62, 0x7A, 0x28, 0xDC, 0x6B, 0x2B, 0x92, 0xAB, 0x6C, 0x1B, 0x04,
	0x1D, 0x0A, 0x36, 0x39, 0x6A, 0x0D, 0x06, 0xAF, 0xF3, 0x04, 0x57, 0x15,
	0x84, 0x03, 0x67, 0x83, 0x1A, 0x67, 0xF2, 0x20, 0x6D, 0x60, 0xC2, 0xB6,
	0xF4, 0x69, 0x93, 0x0C, 0x83, 0x6E, 0xA3, 0x9A, 0x13, 0xD1, 0xBE, 0x0B,
	0x64, 0xD6, 0x8E, 0x9D, 0xFD, 0xDF, 0xDF, 0x27, 0x8A, 0xD8, 0xEF, 0xB1,
	0x14, 0xBC, 0x7A, 0x12, 0x63, 0xBB, 0x4A, 0x84, 0xFA, 0xB2, 0x1B, 0x3E,
	0x8D, 0xB5, 0x2B, 0xA8, 0x00, 0xBD, 0x26, 0x5D, 0x77, 0xBA, 0x16, 0xCB,
	0xEE, 0xB3, 0x47, 0x71, 0x99, 0xB4, 0x77, 0xE7, 0x07, 0xD0, 0xE2, 0x44,
	0x70, 0xD7, 0xD2, 0xD2, 0xE9, 0xDE, 0x83, 0x68, 0x9E, 0xD9, 0xB3, 0xFE,
	0x0E, 0x66, 0xAE, 0x6F, 0x79, 0x61, 0x9E, 0xF9, 0xE0, 0x68, 0xCF, 0x43,
	0x97, 0x6F, 0xFF, 0xD5, 0x09, 0x0B, 0x6A, 0x76, 0x7E, 0x0C, 0x5A, 0xE0,
	0xE7, 0x05, 0x0B, 0x5A, 0x90, 0x02, 0x3B, 0xCC, 0xBD, 0x00, 0xD4, 0x41,
	0xCA, 0x07, 0xE4, 0xD7, 0x53, 0x0E, 0xB5, 0x6D, 0x24, 0x09, 0x85, 0xFB,
	0xBA, 0x6D, 0x10, 0x58, 0xCD, 0x6A, 0x20, 0xCE, 0x54, 0x63, 0x71, 0x74,
	0x23, 0x64, 0x41, 0xE2, 0xB3, 0xDB, 0x5C, 0x73, 0xC4, 0xDC, 0x6C, 0xE5,
	0x5D, 0xD5, 0x3D, 0x5F, 0x2A, 0xD2, 0x0D, 0xC9, 0xB4, 0xB6, 0x98, 0x6A,
	0xC3, 0xB1, 0xA8, 0xFC, 0x5A, 0xB8, 0xF9, 0x46, 0x2D, 0xBF, 0xC9, 0xD0,
	0xA0, 0xB7, 0xC4, 0x25, 0xD7, 0xB0, 0xF4, 0xB3, 0x4E, 0xB9, 0xA5, 0x09,
	0x39, 0xBE, 0x95, 0x9F, 0xA7, 0xDA, 0x00, 0x3C, 0xD0, 0xDD, 0x30, 0xAA,
	0x49, 0xD4, 0x61, 0x10, 0x3E, 0xD3, 0x51, 0x86, 0xAE, 0x6C, 0x4C, 0x17,
	0xD9, 0x6B, 0x7C, 0x81, 0x40, 0x62, 0x2D, 0x3B, 0x37, 0x65, 0x1D, 0xAD,
	0xA9, 0x01, 0x88, 0x0E, 0xDE, 0x06, 0xB8, 0x98, 0x47, 0x0F, 0xE9, 0x22,
	0x30, 0x08, 0xD9, 0xB4, 0x86, 0x6E, 0xF4, 0x89, 0xF1, 0x69, 0xC4, 0x1F,
	0x68, 0x60, 0x95, 0xA5, 0x1F, 0x67, 0xA5, 0x33, 0x81, 0x03, 0x30, 0x90,
	0xF6, 0x04, 0x00, 0x06, 0x6F, 0x0D, 0x51, 0xBC, 0x18, 0x0A, 0x61, 0x2A,
	0x88, 0xB5, 0x7C, 0xBB, 0xFF, 0xB2, 0x4C, 0x2D, 0x66, 0xBB, 0x1D, 0x97,
	0x11, 0xBC, 0x2D, 0x01, 0x8F, 0xD8, 0xB8, 0xA2, 0xF8, 0xDF, 0x88, 0x34,
	0x61, 0xD6, 0xD9, 0x8E, 0x16, 0xD1, 0xE9, 0x18, 0x9B, 0xD9, 0xE4, 0xED,
	0xEC, 0xDE, 0xD4, 0x7B, 0x75, 0xD7, 0x85, 0xC1, 0x02, 0xD0, 0xB5, 0x57,
	0x9C, 0xB4, 0x20, 0xF4, 0xEB, 0xB3, 0x10, 0x62, 0x72, 0xBA, 0x41, 0xD8,
	0x05, 0xBD, 0x71, 0x4E, 0x95, 0x02, 0x6C, 0xDF, 0xE2, 0x05, 0x5C, 0x49,
	0x7B, 0x0C, 0x0D, 0xF3, 0x0C, 0x0B, 0x3D, 0x65, 0x92, 0x6F, 0xA8, 0xC6,
	0xE5, 0x68, 0x98, 0x50, 0x7C, 0x61, 0xC9, 0xEA, 0x0B, 0x66, 0xF9, 0x7C,
	0xCB, 0xDC, 0x95, 0xD1, 0xBC, 0xDB, 0xA5, 0x47, 0x25, 0xD2, 0xF4, 0xFD,
	0x52, 0xD5, 0xC4, 0x6B, 0xCC, 0xB1, 0x51, 0xC8, 0xBB, 0xB6, 0x61, 0x5E,
	0x22, 0xBF, 0x30, 0xE4, 0x55, 0xB8, 0x00, 0x72, 0xC5, 0x07, 0x1D, 0xE3,
	0xB2, 0x00, 0x2D, 0x75, 0x2B, 0x09, 0x7C, 0xCF, 0x5C, 0x0E, 0x4C, 0x59,
	0xC2, 0x6A, 0xD9, 0xFA, 0xB5, 0x6D, 0xE9, 0x6C, 0x2C, 0x64, 0xB8, 0xD6,
	0x5B, 0x63, 0x88, 0x40, 0xD6, 0x6B, 0x85, 0xB5, 0xA1, 0x6C, 0xB5, 0x23,
	0x38, 0x65, 0xE4, 0x99, 0x4F, 0x62, 0xD4, 0x0F, 0xD1, 0x06, 0x41, 0xAC,
	0xA6, 0x01, 0x71, 0x3A, 0x3F, 0x08, 0x20, 0x80, 0x48, 0x0F, 0x10, 0x16,
	0xD8, 0xB0, 0x0D, 0x87, 0xAF, 0xB7, 0x3D, 0x11, 0x36, 0xBE, 0x6C, 0xAB,
	0x41, 0xB9, 0x5C, 0x3D, 0xDF, 0xDD, 0xC9, 0x9E, 0xA8, 0xDA, 0xF9, 0x08,
	0x31, 0xD3, 0xA8, 0xB2, 0x46, 0xD4, 0x98, 0x24, 0xF0, 0xB2, 0xB5, 0x19,
	0x87, 0xB5, 0x85, 0x8F, 0x1E, 0xBC, 0xD4, 0x35, 0x69, 0xBB, 0xE4, 0xA3,
	0xF7, 0xDF, 0x71, 0x00, 0x80, 0xD8, 0x41, 0x96, 0x19, 0xD1, 0x10, 0x2C,
	0x6E, 0xD6, 0x20, 0xBA, 0xFE, 0x69, 0x3D, 0x2B, 0x89, 0x6E, 0x0D, 0xBD,
	0x10, 0x67, 0x5C, 0x07, 0x67, 0x60, 0x6C, 0x91, 0xF9, 0x04, 0xF9, 0x32,
	0x8E, 0x03, 0xC9, 0xA4, 0x17, 0x0A, 0x98, 0x1E, 0x60, 0x0D, 0xA8, 0x88,
	0xED, 0x05, 0xA5, 0x7D, 0x9A, 0x02, 0x95, 0xEB, 0x03, 0x0B, 0xC4, 0x51,
	0x74, 0x0C, 0xF4, 0xC7, 0xEA, 0x68, 0x61, 0x64, 0x9D, 0x6F, 0x51, 0xF2,
	0x04, 0x66, 0x00, 0x48, 0x73, 0x61, 0x30, 0xDE, 0xE3, 0xDE, 0x2D, 0x4F,
	0x94, 0xD9, 0x1D, 0xD9, 0x0D, 0xD0, 0x4C, 0x63, 0x7A, 0xD7, 0x7C, 0xF5,
	0xE4, 0xB3, 0xE9, 0x56, 0x93, 0xB4, 0xD9, 0xC0, 0x0A, 0xBD, 0x88, 0x7A,
	0x7D, 0xBA, 0xB8, 0xEC
};

unsigned char unk_82001E78[1024] = {
	0x3F, 0xC4, 0x7C, 0xDA, 0x48, 0xC3, 0x4C, 0x4C, 0xD1, 0xCA, 0x1D, 0xF6,
	0xA6, 0xCD, 0x2D, 0x60, 0x38, 0xA9, 0xB8, 0xC3, 0x4F, 0xAE, 0x88, 0x55,
	0xD6, 0xA7, 0xD9, 0xEF, 0xA1, 0xA0, 0xE9, 0x79, 0x31, 0x1F, 0xF4, 0xE8,
	0x46, 0x18, 0xC4, 0x7E, 0xDF, 0x11, 0x95, 0xC4, 0xA8, 0x16, 0xA5, 0x52,
	0x36, 0x72, 0x30, 0xF1, 0x41, 0x75, 0x00, 0x67, 0xD8, 0x7C, 0x51, 0xDD,
	0xAF, 0x7B, 0x61, 0x4B, 0x22, 0x73, 0x6C, 0xBE, 0x55, 0x74, 0x5C, 0x28,
	0xCC, 0x7D, 0x0D, 0x92, 0xBB, 0x7A, 0x3D, 0x04, 0x25, 0x1E, 0xA8, 0xA7,
	0x52, 0x19, 0x98, 0x31, 0xCB, 0x10, 0xC9, 0x8B, 0xBC, 0x17, 0xF9, 0x1D,
	0x2C, 0xA8, 0xE4, 0x8C, 0x5B, 0xAF, 0xD4, 0x1A, 0xC2, 0xA6, 0x85, 0xA0,
	0xB5, 0xA1, 0xB5, 0x36, 0x2B, 0xC5, 0x20, 0x95, 0x5C, 0xC2, 0x10, 0x03,
	0xC5, 0xCB, 0x41, 0xB9, 0xB2, 0xCC, 0x71, 0x2F, 0x04, 0xAA, 0x5C, 0x12,
	0x73, 0xAD, 0x6C, 0x84, 0xEA, 0xA4, 0x3D, 0x3E, 0x9D, 0xA3, 0x0D, 0xA8,
	0x03, 0xC7, 0x98, 0x0B, 0x74, 0xC0, 0xA8, 0x9D, 0xED, 0xC9, 0xF9, 0x27,
	0x9A, 0xCE, 0xC9, 0xB1, 0x0A, 0x71, 0xD4, 0x20, 0x7D, 0x76, 0xE4, 0xB6,
	0xE4, 0x7F, 0xB5, 0x0C, 0x93, 0x78, 0x85, 0x9A, 0x0D, 0x1C, 0x10, 0x39,
	0x7A, 0x1B, 0x20, 0xAF, 0xE3, 0x12, 0x71, 0x15, 0x94, 0x15, 0x41, 0x83,
	0x19, 0x1D, 0x4C, 0x76, 0x6E, 0x1A, 0x7C, 0xE0, 0xF7, 0x13, 0x2D, 0x5A,
	0x80, 0x14, 0x1D, 0xCC, 0x1E, 0x70, 0x88, 0x6F, 0x69, 0x77, 0xB8, 0xF9,
	0xF0, 0x7E, 0xE9, 0x43, 0x87, 0x79, 0xD9, 0xD5, 0x17, 0xC6, 0xC4, 0x44,
	0x60, 0xC1, 0xF4, 0xD2, 0xF9, 0xC8, 0xA5, 0x68, 0x8E, 0xCF, 0x95, 0xFE,
	0x10, 0xAB, 0x00, 0x5D, 0x67, 0xAC, 0x30, 0xCB, 0xFE, 0xA5, 0x61, 0x71,
	0x89, 0xA2, 0x51, 0xE7, 0x49, 0x18, 0x3D, 0x4A, 0x3E, 0x1F, 0x0D, 0xDC,
	0xA7, 0x16, 0x5C, 0x66, 0xD0, 0x11, 0x6C, 0xF0, 0x4E, 0x75, 0xF9, 0x53,
	0x39, 0x72, 0xC9, 0xC5, 0xA0, 0x7B, 0x98, 0x7F, 0xD7, 0x7C, 0xA8, 0xE9,
	0x47, 0xC3, 0xB5, 0x78, 0x30, 0xC4, 0x85, 0xEE, 0xA9, 0xCD, 0xD4, 0x54,
	0xDE, 0xCA, 0xE4, 0xC2, 0x40, 0xAE, 0x71, 0x61, 0x37, 0xA9, 0x41, 0xF7,
	0xAE, 0xA0, 0x10, 0x4D, 0xD9, 0xA7, 0x20, 0xDB, 0x54, 0xAF, 0x2D, 0x2E,
	0x23, 0xA8, 0x1D, 0xB8, 0xBA, 0xA1, 0x4C, 0x02, 0xCD, 0xA6, 0x7C, 0x94,
	0x53, 0xC2, 0xE9, 0x37, 0x24, 0xC5, 0xD9, 0xA1, 0xBD, 0xCC, 0x88, 0x1B,
	0xCA, 0xCB, 0xB8, 0x8D, 0x5A, 0x74, 0xA5, 0x1C, 0x2D, 0x73, 0x95, 0x8A,
	0xB4, 0x7A, 0xC4, 0x30, 0xC3, 0x7D, 0xF4, 0xA6, 0x5D, 0x19, 0x61, 0x05,
	0x2A, 0x1E, 0x51, 0x93, 0xB3, 0x17, 0x00, 0x29, 0xC4, 0x10, 0x30, 0xBF,
	0x72, 0x76, 0x1D, 0x82, 0x05, 0x71, 0x2D, 0x14, 0x9C, 0x78, 0x7C, 0xAE,
	0xEB, 0x7F, 0x4C, 0x38, 0x75, 0x1B, 0xD9, 0x9B, 0x02, 0x1C, 0xE9, 0x0D,
	0x9B, 0x15, 0xB8, 0xB7, 0xEC, 0x12, 0x88, 0x21, 0x7C, 0xAD, 0x95, 0xB0,
	0x0B, 0xAA, 0xA5, 0x26, 0x92, 0xA3, 0xF4, 0x9C, 0xE5, 0xA4, 0xC4, 0x0A,
	0x7B, 0xC0, 0x51, 0xA9, 0x0C, 0xC7, 0x61, 0x3F, 0x95, 0xCE, 0x30, 0x85,
	0xE2, 0xC9, 0x00, 0x13, 0x6F, 0xC1, 0x0D, 0xE6, 0x18, 0xC6, 0x3D, 0x70,
	0x81, 0xCF, 0x6C, 0xCA, 0xF6, 0xC8, 0x5C, 0x5C, 0x68, 0xAC, 0xC9, 0xFF,
	0x1F, 0xAB, 0xF9, 0x69, 0x86, 0xA2, 0xA8, 0xD3, 0xF1, 0xA5, 0x98, 0x45,
	0x61, 0x1A, 0x85, 0xD4, 0x16, 0x1D, 0xB5, 0x42, 0x8F, 0x14, 0xE4, 0xF8,
	0xF8, 0x13, 0xD4, 0x6E, 0x66, 0x77, 0x41, 0xCD, 0x11, 0x70, 0x71, 0x5B,
	0x88, 0x79, 0x20, 0xE1, 0xFF, 0x7E, 0x10, 0x77, 0xD2, 0x7C, 0xFF, 0xFA,
	0xA5, 0x7B, 0xCF, 0x6C, 0x3C, 0x72, 0x9E, 0xD6, 0x4B, 0x75, 0xAE, 0x40,
	0xD5, 0x11, 0x3B, 0xE3, 0xA2, 0x16, 0x0B, 0x75, 0x3B, 0x1F, 0x5A, 0xCF,
	0x4C, 0x18, 0x6A, 0x59, 0xDC, 0xA7, 0x77, 0xC8, 0xAB, 0xA0, 0x47, 0x5E,
	0x32, 0xA9, 0x16, 0xE4, 0x45, 0xAE, 0x26, 0x72, 0xDB, 0xCA, 0xB3, 0xD1,
	0xAC, 0xCD, 0x83, 0x47, 0x35, 0xC4, 0xD2, 0xFD, 0x42, 0xC3, 0xE2, 0x6B,
	0xCF, 0xCB, 0xEF, 0x9E, 0xB8, 0xCC, 0xDF, 0x08, 0x21, 0xC5, 0x8E, 0xB2,
	0x56, 0xC2, 0xBE, 0x24, 0xC8, 0xA6, 0x2B, 0x87, 0xBF, 0xA1, 0x1B, 0x11,
	0x26, 0xA8, 0x4A, 0xAB, 0x51, 0xAF, 0x7A, 0x3D, 0xC1, 0x10, 0x67, 0xAC,
	0xB6, 0x17, 0x57, 0x3A, 0x2F, 0x1E, 0x06, 0x80, 0x58, 0x19, 0x36, 0x16,
	0xC6, 0x7D, 0xA3, 0xB5, 0xB1, 0x7A, 0x93, 0x23, 0x28, 0x73, 0xC2, 0x99,
	0x5F, 0x74, 0xF2, 0x0F, 0xE9, 0x12, 0xDF, 0x32, 0x9E, 0x15, 0xEF, 0xA4,
	0x07, 0x1C, 0xBE, 0x1E, 0x70, 0x1B, 0x8E, 0x88, 0xEE, 0x7F, 0x1B, 0x2B,
	0x99, 0x78, 0x2B, 0xBD, 0x00, 0x71, 0x7A, 0x07, 0x77, 0x76, 0x4A, 0x91,
	0xE7, 0xC9, 0x57, 0x00, 0x90, 0xCE, 0x67, 0x96, 0x09, 0xC7, 0x36, 0x2C,
	0x7E, 0xC0, 0x06, 0xBA, 0xE0, 0xA4, 0x93, 0x19, 0x97, 0xA3, 0xA3, 0x8F,
	0x0E, 0xAA, 0xF2, 0x35, 0x79, 0xAD, 0xC2, 0xA3, 0xF4, 0xA5, 0xCF, 0x56,
	0x83, 0xA2, 0xFF, 0xC0, 0x1A, 0xAB, 0xAE, 0x7A, 0x6D, 0xAC, 0x9E, 0xEC,
	0xF3, 0xC8, 0x0B, 0x4F, 0x84, 0xCF, 0x3B, 0xD9, 0x1D, 0xC6, 0x6A, 0x63,
	0x6A, 0xC1, 0x5A, 0xF5, 0xFA, 0x7E, 0x47, 0x64, 0x8D, 0x79, 0x77, 0xF2,
	0x14, 0x70, 0x26, 0x48, 0x63, 0x77, 0x16, 0xDE, 0xFD, 0x13, 0x83, 0x7D,
	0x8A, 0x14, 0xB3, 0xEB, 0x13, 0x1D, 0xE2, 0x51, 0x64, 0x1A, 0xD2, 0xC7,
	0xA4, 0xA0, 0xBE, 0x6A, 0xD3, 0xA7, 0x8E, 0xFC, 0x4A, 0xAE, 0xDF, 0x46,
	0x3D, 0xA9, 0xEF, 0xD0, 0xA3, 0xCD, 0x7A, 0x73, 0xD4, 0xCA, 0x4A, 0xE5,
	0x4D, 0xC3, 0x1B, 0x5F, 0x3A, 0xC4, 0x2B, 0xC9, 0xAA, 0x7B, 0x36, 0x58,
	0xDD, 0x7C, 0x06, 0xCE, 0x44, 0x75, 0x57, 0x74, 0x33, 0x72, 0x67, 0xE2,
	0xAD, 0x16, 0xF2, 0x41, 0xDA, 0x11, 0xC2, 0xD7, 0x43, 0x18, 0x93, 0x6D,
	0x34, 0x1F, 0xA3, 0xFB, 0xB9, 0x17, 0xAE, 0x0E, 0xCE, 0x10, 0x9E, 0x98,
	0x57, 0x19, 0xCF, 0x22, 0x20, 0x1E, 0xFF, 0xB4, 0xBE, 0x7A, 0x6A, 0x17,
	0xC9, 0x7D, 0x5A, 0x81, 0x50, 0x74, 0x0B, 0x3B, 0x27, 0x73, 0x3B, 0xAD,
	0xB7, 0xCC, 0x26, 0x3C, 0xC0, 0xCB, 0x16, 0xAA, 0x59, 0xC2, 0x47, 0x10,
	0x2E, 0xC5, 0x77, 0x86, 0xB0, 0xA1, 0xE2, 0x25, 0xC7, 0xA6, 0xD2, 0xB3,
	0x5E, 0xAF, 0x83, 0x09, 0x29, 0xA8, 0xB3, 0x9F, 0x9F, 0xCE, 0x9E, 0xA2,
	0xE8, 0xC9, 0xAE, 0x34, 0x71, 0xC0, 0xFF, 0x8E, 0x06, 0xC7, 0xCF, 0x18,
	0x98, 0xA3, 0x5A, 0xBB, 0xEF, 0xA4, 0x6A, 0x2D, 0x76, 0xAD, 0x3B, 0x97,
	0x01, 0xAA, 0x0B, 0x01, 0x91, 0x15, 0x16, 0x90, 0xE6, 0x12, 0x26, 0x06,
	0x7F, 0x1B, 0x77, 0xBC, 0x08, 0x1C, 0x47, 0x2A, 0x96, 0x78, 0xD2, 0x89,
	0xE1, 0x7F, 0xE2, 0x1F, 0x78, 0x76, 0xB3, 0xA5, 0x0F, 0x71, 0x83, 0x33,
	0x82, 0x79, 0x8E, 0xC6, 0xF5, 0x7E, 0xBE, 0x50, 0x6C, 0x77, 0xEF, 0xEA,
	0x1B, 0x70, 0xDF, 0x7C, 0x85, 0x14, 0x4A, 0xDF, 0xF2, 0x13, 0x7A, 0x49,
	0x6B, 0x1A, 0x2B, 0xF3, 0x1C, 0x1D, 0x1B, 0x65, 0x8C, 0xA2, 0x06, 0xF4,
	0xFB, 0xA5, 0x36, 0x62, 0x62, 0xAC, 0x67, 0xD8, 0x15, 0xAB, 0x57, 0x4E,
	0x8B, 0xCF, 0xC2, 0xED, 0xFC, 0xC8, 0xF2, 0x7B, 0x65, 0xC1, 0xA3, 0xC1,
	0x12, 0xC6, 0x93, 0x57
};

// Im overdoing it with the static array sizes I know
unsigned int dword_834A73A4[100];

unsigned int dword_832E05C8[1] = {
	1
};

// 1mb data should be plenty, more than I probly need
unsigned char unk_835C4AA0[0x100000];

unsigned int off_832F5EB8[1] = {
	(unsigned int)unk_835C4AA0
};

// more than I need again
unsigned int dword_837FD224[100];

//more than I need again
unsigned int dword_837FD230[100];

//more than I need again
unsigned int dword_83B1D140[100];

//more than I need again
unsigned int dword_83B1D144[100];

// just making sure I have enough space
unsigned char unk_83441544[0x100000];

unsigned int off_83274C18[1] = {
	(unsigned int)unk_83441544
};

// just making sure I have enough space
unsigned char unk_8345E068[0x100000];

unsigned int off_83274C20[1] = {
	(unsigned int)unk_8345E068
};

// just making sure I have enough space
unsigned char unk_8345FC68[0x100000];

unsigned int off_83274C24[1] = {
	(unsigned int)unk_8345FC68
};

// just making sure I have enough space
unsigned char unk_83487BA8[0x100000];

unsigned int off_83274C2C[1] = {
	(unsigned int)unk_83487BA8
};

unsigned char unk_834AACE8[0x48];

unsigned int dword_834A9ED8[100];

unsigned char unk_834B1878[0x100000];

void __declspec(naked) sub_82B8BB78() {
	__asm {
		//lis	  r9, ((dword_837FD224+0x10000)@h)
		lau   r9, dword_837FD224
		xor	  r10, r3, r4
		//addi	  r7, r9, -0x2DDC // dword_837FD224
		lal   r7, r9, dword_837FD224
		slwi	  r8, r10, 16
		mullw	  r11, r10, r5
		//stw	  r11, ((dword_837FD228+0x2DDC)@l)(r7)
		stw   r11, 4(r7)
		xoris	  r6, r8, 0x6576
		or	  r11, r6, r10
		//stw	  r11, dword_837FD224@l(r9)
		stw   r11, 0(r7)
		blr
	}
}

void __declspec(naked) sub_82576588() {
	__asm {
		cmpwi	  cr6, r4, 0
		blelr	  cr6
		addi	  r10, r4, -1
		addi	  r11, r3, -4
		srwi	  r10, r10, 2
		addi	  r10, r10, 1
		mtspr	CTR, r10

loc_825765A4:				// CODE XREF: sub_82576588+44j
		lwz	  r10, 4(r11)
		lbz	  r9, 4(r11)
		mr	  r8, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		mr	  r6, r9
		extlwi	  r5, r8, 16,8
		or	  r4, r5, r7
		or	  r3, r4, r9
		stwu	  r3, 4(r11)
		bdnz	  loc_825765A4
		blr
	}
}

void __declspec(naked) sub_82B8BBA0() {
	__asm {
		//lis	  r11, ((dword_837FD224+0x10000)@h)
		lau    r11, dword_837FD224
		cmpwi	  cr6, r4, 0
		//addi	  r7, r11, -0x2DDC // dword_837FD224
		lal   r7, r11, dword_837FD224
		//lwz	  r10, dword_837FD224@l(r11)
		lwz   r10, 0(r7)
		ble	  cr6, loc_82B8BBEC
		addi	  r9, r4, -1
		//lwz	  r8, ((dword_837FD228+0x2DDC)@l)(r7)
		lwz    r8, 4(r7)
		addi	  r11, r3, -4
		srwi	  r9, r9, 2
		addi	  r9, r9, 1
		mtspr	CTR, r9
		lis	  r9, 0x2E9 // 0x2E90EDD
		ori	  r9, r9, 0xEDD	// 0x2E90EDD

loc_82B8BBD4:				// CODE XREF: sub_82B8BBA0+48j
		lwz	  r6, 4(r11)
		xor	  r5, r6, r10
		mullw	  r10, r10, r9
		stwu	  r5, 4(r11)
		add	  r10, r10, r8
		bdnz	  loc_82B8BBD4

loc_82B8BBEC:				// CODE XREF: sub_82B8BBA0+10j
		//stw	  r10, ((dword_837FD224+0x2DDC)@l)(r7)
		stw	  r10, 0(r7)
		blr
	}
}

void __declspec(naked) sub_82B8BFB8() {
	__asm {
		//lis	  r11, ((dword_837FD230+0x10000)@h)
		lau   r11, dword_837FD230
		lal   r11, r11, dword_837FD230
		//lwz	  r11, dword_837FD230@l(r11)
		lwz   r11, 0(r11)
		cmplwi	  cr6, r11, 5
		beq	  cr6, loc_82B8BFD8
		cmplwi	  cr6, r11, 0
		beq	  cr6, loc_82B8BFD8
		li	  r3, 0
		blr
// ---------------------------------------------------------------------------

loc_82B8BFD8:				// CODE XREF: sub_82B8BFB8+Cj
					// sub_82B8BFB8+14j
		//b	  loc_82563940

loc_82563940:
		//lis	  r11, ((dword_83B1D140+0x10000)@h)
		lau   r11, dword_83B1D140
		lal   r11, r11, dword_83B1D140
		//lwz	  r11, dword_83B1D140@l(r11)
		lwz   r11, 0(r11)
		cmplwi	  cr6, r11, 0
		beq	  cr6, loc_82563968
		//lis	  r11, ((dword_83B1D144+0x10000)@h)
		lau   r11, dword_83B1D144
		lal   r11, r11, dword_83B1D144
		//lwz	  r11, dword_83B1D144@l(r11)
		lwz   r11, 0(r11)
		cmplwi	  cr6, r11, 0
		beq	  cr6, loc_82563968
		lwz	  r3, 0x20(r11)
		blr
// ---------------------------------------------------------------------------

loc_82563968:				// CODE XREF: sub_82B8BFB8-62866Cj
					// sub_82B8BFB8-62865Cj
		li	  r3, 0
		blr
	}
}

void __declspec(naked) sub_825D2050() {
	__asm {
		//lis       r11, off_83274C18@h
		lau    r11, off_83274C18
		lal    r11, r11, off_83274C18
		//lwz       r3, off_83274C18@l(r11)
		lwz    r3, 0(r11)
		blr
	}
}

void __declspec(naked) sub_825D2060() {
	__asm {
		//lis       r11, off_83274C20@h
		lau    r11, off_83274C20
		lal    r11, r11, off_83274C20
		//lwz       r3, off_83274C20@l(r11)
		lwz    r3, 0(r11)
		blr
	}
}

void __declspec(naked) sub_827D2630() {
	__asm {
		//lis       r11, off_83274C24@h
		lau    r11, off_83274C24
		lal    r11, r11, off_83274C24
		//lwz       r3, off_83274C24@l(r11)
		lwz    r3, 0(r11)
		blr
	}
}

void __declspec(naked) sub_825D20A0() {
	__asm {
		//lis       r11, off_83274C2C@h
		lau    r11, off_83274C2C
		lal    r11, r11, off_83274C2C
		//lwz       r3, off_83274C2C@l(r11)
		lwz    r3, 0(r11)
		blr
	}
}

void __declspec(naked) sub_8256C3B0() {
	__asm {
		mfspr	r12, LR
		//bl	  __savegprlr_29
		std       r29, -0x20(r1)
		std       r30, -0x18(r1)
		std       r31, -0x10(r1)
		stw       r12, -0x8(r1)

		stwu	  r1, -0x70(r1)
		ld	  r11, 0x10(r3)
		mr	  r29, r4
		lbz	  r10, 0x16(r3)
		mr	  r31, r3
		sldi	  r9, r11, 8
		lbz	  r8, 0x15(r3)
		lbz	  r4, 0x12(r3)
		or	  r6, r10, r9
		lbz	  r7, 0x14(r3)
		lbz	  r5, 0x13(r3)
		sldi	  r3, r6, 8
		lbz	  r11, 0x11(r31)
		lbz	  r10, 0x10(r31)
		or	  r9, r3, r8
		sldi	  r8, r9, 8
		or	  r7, r8, r7
		sldi	  r6, r7, 8
		or	  r5, r6, r5
		sldi	  r3, r5, 8
		or	  r9, r3, r4
		sldi	  r8, r9, 8
		or	  r7, r8, r11
		sldi	  r6, r7, 8
		or	  r5, r6, r10
		std	  r5, 0x10(r31)
		lbz	  r4, 0x18(r31)
		lwz	  r3, 0x18(r31)
		mr	  r11, r3
		insrwi	  r11, r3, 16,0
		rlwinm	  r10, r3, 24,16,23
		extlwi	  r9, r11, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r4
		stw	  r7, 0x18(r31)
		lbz	  r6, 0x1C(r31)
		lwz	  r5, 0x1C(r31)
		mr	  r4, r5
		insrwi	  r4, r5, 16,0
		rlwinm	  r3, r5, 24,16,23
		extlwi	  r11, r4, 16,8
		or	  r10, r11, r3
		or	  r9, r10, r6
		stw	  r9, 0x1C(r31)
		lbz	  r8, 0x34(r31)
		lwz	  r7, 0x34(r31)
		mr	  r6, r7
		insrwi	  r6, r7, 16,0
		rlwinm	  r5, r7, 24,16,23
		extlwi	  r4, r6, 16,8
		or	  r3, r4, r5
		or	  r11, r3, r8
		stw	  r11, 0x34(r31)
		lbz	  r10, 0x38(r31)
		lwz	  r9, 0x38(r31)
		mr	  r8, r9
		insrwi	  r8, r9, 16,0
		rlwinm	  r7, r9, 24,16,23
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r10
		stw	  r4, 0x38(r31)
		lbz	  r3, 0x3C(r31)
		lwz	  r11, 0x3C(r31)
		mr	  r10, r11
		insrwi	  r10, r11, 16,0
		rlwinm	  r9, r11, 24,16,23
		extlwi	  r8, r10, 16,8
		or	  r7, r8, r9
		or	  r6, r7, r3
		stw	  r6, 0x3C(r31)
		lbz	  r5, 0x40(r31)
		lhz	  r4, 0x40(r31)
		rotlwi	  r3, r4, 8
		or	  r11, r3, r5
		sth	  r11, 0x40(r31)
		lbz	  r9, 0x42(r31)
		lhz	  r8, 0x42(r31)
		rotlwi	  r7, r8, 8
		or	  r6, r7, r9
		sth	  r6, 0x42(r31)
		lbz	  r4, 0x44(r31)
		lhz	  r3, 0x44(r31)
		rotlwi	  r11, r3, 8
		or	  r10, r11, r4
		sth	  r10, 0x44(r31)
		lbz	  r8, 0x46(r31)
		lhz	  r7, 0x46(r31)
		rotlwi	  r6, r7, 8
		or	  r5, r6, r8
		sth	  r5, 0x46(r31)
		lbz	  r3, 0x48(r31)
		lhz	  r11, 0x48(r31)
		rotlwi	  r10, r11, 8
		or	  r9, r10, r3
		sth	  r9, 0x48(r31)
		lbz	  r7, 0x4A(r31)
		lhz	  r6, 0x4A(r31)
		rotlwi	  r5, r6, 8
		or	  r4, r5, r7
		sth	  r4, 0x4A(r31)
		lbz	  r11, 0x4C(r31)
		lhz	  r10, 0x4C(r31)
		rotlwi	  r9, r10, 8
		or	  r8, r9, r11
		sth	  r8, 0x4C(r31)
		lbz	  r6, 0x4E(r31)
		lhz	  r5, 0x4E(r31)
		rotlwi	  r4, r5, 8
		or	  r3, r4, r6
		sth	  r3, 0x4E(r31)
		lbz	  r10, 0x50(r31)
		lhz	  r9, 0x50(r31)
		rotlwi	  r8, r9, 8
		or	  r7, r8, r10
		sth	  r7, 0x50(r31)
		lbz	  r5, 0x52(r31)
		lhz	  r4, 0x52(r31)
		rotlwi	  r3, r4, 8
		or	  r11, r3, r5
		sth	  r11, 0x52(r31)
		lbz	  r9, 0x54(r31)
		lhz	  r8, 0x54(r31)
		rotlwi	  r7, r8, 8
		or	  r6, r7, r9
		sth	  r6, 0x54(r31)
		lbz	  r4, 0x56(r31)
		lhz	  r3, 0x56(r31)
		rotlwi	  r11, r3, 8
		or	  r10, r11, r4
		sth	  r10, 0x56(r31)
		lbz	  r6, 0x58(r31)
		lhz	  r8, 0x58(r31)
		rotlwi	  r7, r8, 8
		or	  r5, r7, r6
		sth	  r5, 0x58(r31)
		lbz	  r3, 0x5A(r31)
		lhz	  r11, 0x5A(r31)
		rotlwi	  r10, r11, 8
		or	  r9, r10, r3
		sth	  r9, 0x5A(r31)
		lhz	  r6, 0x5C(r31)
		rotlwi	  r5, r6, 8
		lbz	  r7, 0x5C(r31)
		or	  r4, r5, r7
		sth	  r4, 0x5C(r31)
		lbz	  r11, 0x5E(r31)
		lhz	  r10, 0x5E(r31)
		rotlwi	  r9, r10, 8
		or	  r8, r9, r11
		sth	  r8, 0x5E(r31)
		lbz	  r6, 0x60(r31)
		lhz	  r5, 0x60(r31)
		rotlwi	  r4, r5, 8
		or	  r3, r4, r6
		sth	  r3, 0x60(r31)
		lbz	  r10, 0x62(r31)
		lhz	  r9, 0x62(r31)
		rotlwi	  r8, r9, 8
		or	  r7, r8, r10
		sth	  r7, 0x62(r31)
		lbz	  r5, 0x64(r31)
		lhz	  r4, 0x64(r31)
		rotlwi	  r3, r4, 8
		or	  r11, r3, r5
		sth	  r11, 0x64(r31)
		lbz	  r9, 0x66(r31)
		lhz	  r8, 0x66(r31)
		rotlwi	  r7, r8, 8
		or	  r6, r7, r9
		sth	  r6, 0x66(r31)
		lbz	  r4, 0x68(r31)
		lhz	  r3, 0x68(r31)
		rotlwi	  r11, r3, 8
		or	  r10, r11, r4
		sth	  r10, 0x68(r31)
		lbz	  r8, 0x6A(r31)
		lhz	  r7, 0x6A(r31)
		rotlwi	  r6, r7, 8
		or	  r5, r6, r8
		sth	  r5, 0x6A(r31)
		lbz	  r3, 0x6C(r31)
		lhz	  r11, 0x6C(r31)
		rotlwi	  r10, r11, 8
		or	  r9, r10, r3
		sth	  r9, 0x6C(r31)
		lbz	  r7, 0x6E(r31)
		lhz	  r6, 0x6E(r31)
		rotlwi	  r5, r6, 8
		or	  r4, r5, r7
		sth	  r4, 0x6E(r31)
		lhz	  r11, 0x70(r31)
		rotlwi	  r10, r11, 8
		lbz	  r9, 0x70(r31)
		or	  r8, r10, r9
		sth	  r8, 0x70(r31)
		lhz	  r6, 0x72(r31)
		rotlwi	  r5, r6, 8
		lbz	  r4, 0x72(r31)
		or	  r3, r5, r4
		sth	  r3, 0x72(r31)
		lhz	  r9, 0x74(r31)
		rotlwi	  r8, r9, 8
		lbz	  r10, 0x74(r31)
		or	  r7, r8, r10
		sth	  r7, 0x74(r31)
		lbz	  r5, 0x76(r31)
		lhz	  r4, 0x76(r31)
		rotlwi	  r3, r4, 8
		or	  r11, r3, r5
		sth	  r11, 0x76(r31)
		lbz	  r9, 0x78(r31)
		lhz	  r8, 0x78(r31)
		rotlwi	  r7, r8, 8
		or	  r6, r7, r9
		sth	  r6, 0x78(r31)
		lbz	  r3, 0x7A(r31)
		lhz	  r4, 0x7A(r31)
		rotlwi	  r11, r4, 8
		or	  r10, r11, r3
		sth	  r10, 0x7A(r31)
		lhz	  r8, 0x7C(r31)
		rotlwi	  r7, r8, 8
		lbz	  r6, 0x7C(r31)
		or	  r5, r7, r6
		sth	  r5, 0x7C(r31)
		lhz	  r3, 0x7E(r31)
		rotlwi	  r11, r3, 8
		lbz	  r10, 0x7E(r31)
		or	  r9, r11, r10
		sth	  r9, 0x7E(r31)
		lhz	  r7, 0x80(r31)
		rotlwi	  r6, r7, 8
		lbz	  r5, 0x80(r31)
		or	  r4, r6, r5
		sth	  r4, 0x80(r31)
		lhz	  r11, 0x82(r31)
		rotlwi	  r10, r11, 8
		lbz	  r9, 0x82(r31)
		or	  r8, r10, r9
		sth	  r8, 0x82(r31)
		lhz	  r6, 0x84(r31)
		rotlwi	  r5, r6, 8
		lbz	  r4, 0x84(r31)
		or	  r3, r5, r4
		sth	  r3, 0x84(r31)
		lhz	  r10, 0x86(r31)
		rotlwi	  r9, r10, 8
		lbz	  r8, 0x86(r31)
		or	  r7, r9, r8
		sth	  r7, 0x86(r31)
		lbz	  r5, 0x88(r31)
		lhz	  r4, 0x88(r31)
		rotlwi	  r3, r4, 8
		or	  r11, r3, r5
		sth	  r11, 0x88(r31)
		lbz	  r9, 0x8A(r31)
		lhz	  r8, 0x8A(r31)
		rotlwi	  r7, r8, 8
		or	  r6, r7, r9
		sth	  r6, 0x8A(r31)
		lwz	  r4, 0x90(r31)
		mr	  r3, r4
		insrwi	  r3, r4, 16,0
		lbz	  r11, 0x90(r31)
		rlwinm	  r10, r4, 24,16,23
		extlwi	  r9, r3, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r11
		stw	  r7, 0x90(r31)
		lbz	  r4, 0x94(r31)
		lwz	  r6, 0x94(r31)
		mr	  r5, r6
		insrwi	  r5, r6, 16,0
		rlwinm	  r3, r6, 24,16,23
		extlwi	  r11, r5, 16,8
		or	  r10, r11, r3
		or	  r9, r10, r4
		stw	  r9, 0x94(r31)
		lhz	  r8, 0xA0(r31)
		rotlwi	  r7, r8, 8
		lbz	  r6, 0xA0(r31)
		or	  r5, r7, r6
		sth	  r5, 0xA0(r31)
		//bl	  sub_827D2628
		li        r3, 0xB0
		add	  r11, r3, r31
		li	  r30, 0
		cmpwi	  cr6, r29, 1
		bne	  cr6, loc_8256C840
		lwz	  r30, 0(r11)

loc_8256C840:				// CODE XREF: sub_8256C3B0+488j
		lwz	  r10, 0(r11)
		cmpwi	  cr6, r29, 0
		lbz	  r9, 0(r11)
		mr	  r8, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r9
		stw	  r4, 0(r11)
		lwz	  r3, 4(r11)
		lbz	  r10, 4(r11)
		mr	  r9, r3
		rlwinm	  r8, r3, 24,16,23
		insrwi	  r9, r3, 16,0
		extlwi	  r7, r9, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r10
		stw	  r5, 4(r11)
		lbz	  r3, 8(r11)
		lwz	  r4, 8(r11)
		mr	  r10, r4
		insrwi	  r10, r4, 16,0
		rlwinm	  r9, r4, 24,16,23
		extlwi	  r8, r10, 16,8
		or	  r7, r8, r9
		or	  r6, r7, r3
		stw	  r6, 8(r11)
		lwz	  r5, 0xC(r11)
		lbz	  r4, 0xC(r11)
		mr	  r3, r5
		rlwinm	  r10, r5, 24,16,23
		insrwi	  r3, r5, 16,0
		extlwi	  r9, r3, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r4
		stw	  r7, 0xC(r11)
		bne	  cr6, loc_8256C8DC
		lwz	  r30, 0(r11)

loc_8256C8DC:				// CODE XREF: sub_8256C3B0+524j
		//bl	  sub_827D2628
		li        r3, 0xB0
		mr	  r29, r3
		//bl	  sub_83161040
		li        r3, 0x10
		add	  r11, r29, r3
		cmplwi	  cr6, r30, 0
		add	  r11, r11, r31
		beq	  cr6, loc_8256CCA8
		addi	  r11, r11, -0xC
		mtspr	CTR, r30

loc_8256C900:				//CODE XREF: sub_8256C3B0+8F4j
		ld	  r8, 0x1C(r11)
		lbz	  r7, 0x22(r11)
		lbz	  r5, 0x21(r11)
		insrdi	  r7, r8, 56,0
		lbz	  r3, 0x20(r11)
		lbz	  r8, 0x1F(r11)
		insrdi	  r5, r7, 56,0
		lbz	  r9, 0x1D(r11)
		lbz	  r6, 0x1E(r11)
		insrdi	  r3, r5, 56,0
		lbz	  r4, 0x1C(r11)
		mr	  r5, r9
		insrdi	  r8, r3, 56,0
		insrdi	  r6, r8, 56,0
		insrdi	  r5, r6, 56,0
		insrdi	  r4, r5, 56,0
		std	  r4, 0x1C(r11)
		lwz	  r9, 0x24(r11)
		lbz	  r10, 0x24(r11)
		mr	  r8, r9
		rlwinm	  r7, r9, 24,16,23
		insrwi	  r8, r9, 16,0
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r10
		stw	  r4, 0x24(r11)
		lwz	  r3, 0x28(r11)
		mr	  r10, r3
		insrwi	  r10, r3, 16,0
		lbz	  r6, 0x28(r11)
		rlwinm	  r8, r3, 24,16,23
		extlwi	  r7, r10, 16,8
		or	  r5, r7, r8
		or	  r4, r5, r6
		stw	  r4, 0x28(r11)
		lbz	  r6, 0x40(r11)
		lwz	  r3, 0x40(r11)
		mr	  r10, r3
		rlwinm	  r8, r3, 24,16,23
		insrwi	  r10, r3, 16,0
		extlwi	  r7, r10, 16,8
		or	  r5, r7, r8
		or	  r4, r5, r6
		stw	  r4, 0x40(r11)
		lbz	  r10, 0x44(r11)
		lwz	  r9, 0x44(r11)
		mr	  r8, r9
		rlwinm	  r7, r9, 24,16,23
		insrwi	  r8, r9, 16,0
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r10
		stw	  r4, 0x44(r11)
		lbz	  r6, 0x48(r11)
		lwz	  r3, 0x48(r11)
		mr	  r10, r3
		insrwi	  r10, r3, 16,0
		rlwinm	  r8, r3, 24,16,23
		extlwi	  r7, r10, 16,8
		or	  r5, r7, r8
		or	  r4, r5, r6
		stw	  r4, 0x48(r11)
		lbz	  r3, 0x4C(r11)
		lhz	  r10, 0x4C(r11)
		insrwi	  r3, r10, 16,8
		sth	  r3, 0x4C(r11)
		lhz	  r7, 0x4E(r11)
		lbz	  r8, 0x4E(r11)
		insrwi	  r8, r7, 16,8
		sth	  r8, 0x4E(r11)
		lbz	  r4, 0x50(r11)
		lhz	  r5, 0x50(r11)
		insrwi	  r4, r5, 16,8
		sth	  r4, 0x50(r11)
		lbz	  r10, 0x52(r11)
		lhz	  r9, 0x52(r11)
		insrwi	  r10, r9, 16,8
		sth	  r10, 0x52(r11)
		lhz	  r6, 0x54(r11)
		lbz	  r7, 0x54(r11)
		insrwi	  r7, r6, 16,8
		sth	  r7, 0x54(r11)
		lbz	  r4, 0x56(r11)
		lhz	  r3, 0x56(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x56(r11)
		lhz	  r8, 0x58(r11)
		lbz	  r9, 0x58(r11)
		insrwi	  r9, r8, 16,8
		sth	  r9, 0x58(r11)
		lhz	  r5, 0x5A(r11)
		lbz	  r6, 0x5A(r11)
		insrwi	  r6, r5, 16,8
		sth	  r6, 0x5A(r11)
		lhz	  r10, 0x5C(r11)
		lbz	  r3, 0x5C(r11)
		insrwi	  r3, r10, 16,8
		sth	  r3, 0x5C(r11)
		lhz	  r7, 0x5E(r11)
		lbz	  r8, 0x5E(r11)
		insrwi	  r8, r7, 16,8
		sth	  r8, 0x5E(r11)
		lhz	  r4, 0x60(r11)
		lbz	  r5, 0x60(r11)
		insrwi	  r5, r4, 16,8
		sth	  r5, 0x60(r11)
		lbz	  r10, 0x62(r11)
		lhz	  r9, 0x62(r11)
		insrwi	  r10, r9, 16,8
		sth	  r10, 0x62(r11)
		lhz	  r6, 0x64(r11)
		lbz	  r7, 0x64(r11)
		insrwi	  r7, r6, 16,8
		sth	  r7, 0x64(r11)
		lhz	  r3, 0x66(r11)
		lbz	  r4, 0x66(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x66(r11)
		lhz	  r8, 0x68(r11)
		lbz	  r9, 0x68(r11)
		insrwi	  r9, r8, 16,8
		sth	  r9, 0x68(r11)
		lhz	  r5, 0x6A(r11)
		lbz	  r6, 0x6A(r11)
		insrwi	  r6, r5, 16,8
		sth	  r6, 0x6A(r11)
		lhz	  r3, 0x6C(r11)
		lbz	  r10, 0x6C(r11)
		insrwi	  r10, r3, 16,8
		sth	  r10, 0x6C(r11)
		lhz	  r7, 0x6E(r11)
		lbz	  r8, 0x6E(r11)
		insrwi	  r8, r7, 16,8
		sth	  r8, 0x6E(r11)
		lbz	  r5, 0x70(r11)
		lhz	  r4, 0x70(r11)
		insrwi	  r5, r4, 16,8
		sth	  r5, 0x70(r11)
		lhz	  r9, 0x72(r11)
		lbz	  r10, 0x72(r11)
		insrwi	  r10, r9, 16,8
		sth	  r10, 0x72(r11)
		lhz	  r6, 0x74(r11)
		lbz	  r7, 0x74(r11)
		insrwi	  r7, r6, 16,8
		sth	  r7, 0x74(r11)
		lhz	  r3, 0x76(r11)
		lbz	  r4, 0x76(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x76(r11)
		lhz	  r8, 0x78(r11)
		lbz	  r9, 0x78(r11)
		insrwi	  r9, r8, 16,8
		sth	  r9, 0x78(r11)
		lbz	  r6, 0x7A(r11)
		lhz	  r5, 0x7A(r11)
		insrwi	  r6, r5, 16,8
		sth	  r6, 0x7A(r11)
		lbz	  r3, 0x7C(r11)
		lhz	  r10, 0x7C(r11)
		insrwi	  r3, r10, 16,8
		sth	  r3, 0x7C(r11)
		lhz	  r7, 0x7E(r11)
		lbz	  r8, 0x7E(r11)
		insrwi	  r8, r7, 16,8
		sth	  r8, 0x7E(r11)
		lbz	  r5, 0x80(r11)
		lhz	  r4, 0x80(r11)
		insrwi	  r5, r4, 16,8
		sth	  r5, 0x80(r11)
		lbz	  r10, 0x82(r11)
		lhz	  r9, 0x82(r11)
		insrwi	  r10, r9, 16,8
		sth	  r10, 0x82(r11)
		lhz	  r6, 0x84(r11)
		lbz	  r7, 0x84(r11)
		insrwi	  r7, r6, 16,8
		sth	  r7, 0x84(r11)
		lhz	  r3, 0x86(r11)
		lbz	  r4, 0x86(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x86(r11)
		lhz	  r8, 0x88(r11)
		lbz	  r9, 0x88(r11)
		insrwi	  r9, r8, 16,8
		sth	  r9, 0x88(r11)
		lhz	  r6, 0x8A(r11)
		lbz	  r5, 0x8A(r11)
		insrwi	  r5, r6, 16,8
		sth	  r5, 0x8A(r11)
		lbz	  r10, 0x8C(r11)
		lhz	  r3, 0x8C(r11)
		insrwi	  r10, r3, 16,8
		sth	  r10, 0x8C(r11)
		lbz	  r8, 0x8E(r11)
		lhz	  r7, 0x8E(r11)
		insrwi	  r8, r7, 16,8
		sth	  r8, 0x8E(r11)
		lhz	  r5, 0x90(r11)
		lbz	  r4, 0x90(r11)
		insrwi	  r4, r5, 16,8
		sth	  r4, 0x90(r11)
		lhz	  r10, 0x92(r11)
		lbz	  r9, 0x92(r11)
		insrwi	  r9, r10, 16,8
		sth	  r9, 0x92(r11)
		lhz	  r6, 0x94(r11)
		lbz	  r7, 0x94(r11)
		insrwi	  r7, r6, 16,8
		sth	  r7, 0x94(r11)
		lbz	  r4, 0x96(r11)
		lhz	  r3, 0x96(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x96(r11)
		lwz	  r9, 0x9C(r11)
		mr	  r7, r9
		insrwi	  r7, r9, 16,0
		lbz	  r5, 0x9C(r11)
		rlwinm	  r6, r9, 24,16,23
		extlwi	  r4, r7, 16,8
		or	  r3, r4, r6
		or	  r10, r3, r5
		stw	  r10, 0x9C(r11)
		lwz	  r9, 0xA0(r11)
		mr	  r7, r9
		insrwi	  r7, r9, 16,0
		lbz	  r8, 0xA0(r11)
		rlwinm	  r6, r9, 24,16,23
		extlwi	  r4, r7, 16,8
		mr	  r5, r8
		or	  r3, r4, r6
		or	  r10, r3, r8
		stwu	  r10, 0xA0(r11)
		bdnz	  loc_8256C900

loc_8256CCA8:				// CODE XREF: sub_8256C3B0+544j
		addis	  r11, r31, 1
		li	  r10, 0x31
		addi	  r11, r11, -0x14D8
		addi	  r11, r11, 0x5000
		addi	  r11, r11, 0x5000
		mtspr	CTR, r10
		addi	  r10, r11, -2

loc_8256CCC4:				// CODE XREF: sub_8256C3B0+93Cj
		lbz	  r9, 8(r10)
		lhz	  r8, 8(r10)
		insrwi	  r9, r8, 16,8
		clrlwi	  r7, r9, 16
		sth	  r7, 8(r10)
		lhz	  r6, 0x10(r10)
		lbz	  r5, 0x10(r10)
		insrwi	  r5, r6, 16,8
		clrlwi	  r4, r5, 16
		sthu	  r4, 0x10(r10)
		bdnz	  loc_8256CCC4
		lhz	  r9, 0x316(r11)
		addi	  r10, r11, 0x310
		lbz	  r8, 0x316(r11)
		rotlwi	  r7, r9, 8
		or	  r6, r7, r8
		sth	  r6, 0x316(r11)
		lhz	  r4, 0x31E(r11)
		lbz	  r10, 0x31E(r11)
		rotlwi	  r3, r4, 8
		or	  r9, r3, r10
		sth	  r9, 0x31E(r11)
		lbz	  r6, 0x326(r11)
		lhz	  r7, 0x326(r11)
		rotlwi	  r5, r7, 8
		or	  r4, r5, r6
		sth	  r4, 0x326(r11)
		lbz	  r9, 0x32E(r11)
		lhz	  r10, 0x32E(r11)
		rotlwi	  r8, r10, 8
		or	  r7, r8, r9
		sth	  r7, 0x32E(r11)
		lbz	  r4, 0x336(r11)
		lhz	  r5, 0x336(r11)
		rotlwi	  r3, r5, 8
		or	  r10, r3, r4
		sth	  r10, 0x336(r11)
		lbz	  r7, 0x33E(r11)
		lhz	  r8, 0x33E(r11)
		rotlwi	  r6, r8, 8
		or	  r5, r6, r7
		sth	  r5, 0x33E(r11)
		lwzu	  r10, 0x340(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r8, 0(r11)
		rlwinm	  r9, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		insrwi	  r4, r10, 16,0
		rlwinm	  r3, r10, 24,16,23
		lbz	  r10, 0(r11)
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r3
		or	  r7, r8, r10
		stw	  r7, 0(r11)
		addi	  r1, r1, 0x70
		//b	  __restgprlr_29
		ld        r29, -0x20(r1)
		ld        r30, -0x18(r1)
		ld        r31, -0x10(r1)
		lwz       r12, -0x8(r1)
		mtspr   LR, r12
		blr
	}
}

void __declspec(naked) sub_82567D18() {
	__asm {
		ld	  r11, 0x10(r3)
		lbz	  r10, 0x16(r3)
		sldi	  r9, r11, 8
		lbz	  r8, 0x15(r3)
		lbz	  r7, 0x14(r3)
		or	  r6, r10, r9
		lbz	  r5, 0x13(r3)
		lbz	  r4, 0x12(r3)
		sldi	  r11, r6, 8
		lbz	  r10, 0x11(r3)
		lbz	  r9, 0x10(r3)
		or	  r8, r11, r8
		sldi	  r6, r8, 8
		or	  r11, r6, r7
		sldi	  r8, r11, 8
		or	  r7, r8, r5
		sldi	  r6, r7, 8
		or	  r5, r6, r4
		sldi	  r4, r5, 8
		or	  r11, r4, r10
		sldi	  r10, r11, 8
		or	  r9, r10, r9
		std	  r9, 0x10(r3)
		lbz	  r8, 0x18(r3)
		lwz	  r7, 0x18(r3)
		mr	  r6, r7
		insrwi	  r6, r7, 16,0
		rlwinm	  r5, r7, 24,16,23
		extlwi	  r4, r6, 16,8
		or	  r11, r4, r5
		or	  r10, r11, r8
		stw	  r10, 0x18(r3)
		lbz	  r9, 0x1C(r3)
		lwz	  r8, 0x1C(r3)
		mr	  r7, r8
		insrwi	  r7, r8, 16,0
		rlwinm	  r6, r8, 24,16,23
		extlwi	  r5, r7, 16,8
		or	  r4, r5, r6
		or	  r11, r4, r9
		stw	  r11, 0x1C(r3)
		lbz	  r10, 0x34(r3)
		lwz	  r9, 0x34(r3)
		mr	  r8, r9
		insrwi	  r8, r9, 16,0
		rlwinm	  r7, r9, 24,16,23
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r10
		stw	  r4, 0x34(r3)
		lbz	  r11, 0x38(r3)
		lwz	  r10, 0x38(r3)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r7, r9, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r11
		stw	  r5, 0x38(r3)
		lbz	  r4, 0x3C(r3)
		lwz	  r11, 0x3C(r3)
		mr	  r10, r11
		insrwi	  r10, r11, 16,0
		rlwinm	  r9, r11, 24,16,23
		extlwi	  r8, r10, 16,8
		or	  r7, r8, r9
		or	  r6, r7, r4
		stw	  r6, 0x3C(r3)
		lbz	  r5, 0x40(r3)
		lhz	  r4, 0x40(r3)
		rotlwi	  r11, r4, 8
		or	  r10, r11, r5
		sth	  r10, 0x40(r3)
		lbz	  r8, 0x42(r3)
		lhz	  r7, 0x42(r3)
		rotlwi	  r6, r7, 8
		or	  r5, r6, r8
		sth	  r5, 0x42(r3)
		lhz	  r10, 0x44(r3)
		rotlwi	  r9, r10, 8
		lbz	  r11, 0x44(r3)
		or	  r8, r9, r11
		sth	  r8, 0x44(r3)
		lbz	  r6, 0x46(r3)
		lhz	  r5, 0x46(r3)
		rotlwi	  r4, r5, 8
		or	  r11, r4, r6
		sth	  r11, 0x46(r3)
		lbz	  r9, 0x48(r3)
		lhz	  r8, 0x48(r3)
		rotlwi	  r7, r8, 8
		or	  r6, r7, r9
		sth	  r6, 0x48(r3)
		lbz	  r4, 0x4A(r3)
		lhz	  r11, 0x4A(r3)
		rotlwi	  r10, r11, 8
		or	  r9, r10, r4
		sth	  r9, 0x4A(r3)
		lbz	  r7, 0x4C(r3)
		lhz	  r6, 0x4C(r3)
		rotlwi	  r5, r6, 8
		or	  r4, r5, r7
		sth	  r4, 0x4C(r3)
		lbz	  r10, 0x4E(r3)
		lhz	  r9, 0x4E(r3)
		rotlwi	  r8, r9, 8
		or	  r7, r8, r10
		sth	  r7, 0x4E(r3)
		lbz	  r5, 0x50(r3)
		lhz	  r4, 0x50(r3)
		rotlwi	  r11, r4, 8
		or	  r10, r11, r5
		sth	  r10, 0x50(r3)
		lbz	  r8, 0x52(r3)
		lhz	  r7, 0x52(r3)
		rotlwi	  r6, r7, 8
		or	  r5, r6, r8
		sth	  r5, 0x52(r3)
		lbz	  r11, 0x54(r3)
		lhz	  r10, 0x54(r3)
		rotlwi	  r9, r10, 8
		or	  r8, r9, r11
		sth	  r8, 0x54(r3)
		lbz	  r6, 0x56(r3)
		lhz	  r5, 0x56(r3)
		rotlwi	  r4, r5, 8
		or	  r11, r4, r6
		sth	  r11, 0x56(r3)
		lbz	  r7, 0x58(r3)
		lhz	  r9, 0x58(r3)
		rotlwi	  r8, r9, 8
		or	  r6, r8, r7
		sth	  r6, 0x58(r3)
		lbz	  r4, 0x5A(r3)
		lhz	  r11, 0x5A(r3)
		rotlwi	  r10, r11, 8
		or	  r9, r10, r4
		sth	  r9, 0x5A(r3)
		lbz	  r7, 0x5C(r3)
		lhz	  r6, 0x5C(r3)
		rotlwi	  r5, r6, 8
		or	  r4, r5, r7
		sth	  r4, 0x5C(r3)
		lbz	  r10, 0x5E(r3)
		lhz	  r9, 0x5E(r3)
		rotlwi	  r8, r9, 8
		or	  r7, r8, r10
		sth	  r7, 0x5E(r3)
		lbz	  r5, 0x60(r3)
		lhz	  r4, 0x60(r3)
		rotlwi	  r11, r4, 8
		or	  r10, r11, r5
		sth	  r10, 0x60(r3)
		lbz	  r8, 0x62(r3)
		lhz	  r7, 0x62(r3)
		rotlwi	  r6, r7, 8
		or	  r5, r6, r8
		sth	  r5, 0x62(r3)
		lbz	  r11, 0x64(r3)
		lhz	  r10, 0x64(r3)
		rotlwi	  r9, r10, 8
		or	  r8, r9, r11
		sth	  r8, 0x64(r3)
		lbz	  r6, 0x66(r3)
		lhz	  r5, 0x66(r3)
		rotlwi	  r4, r5, 8
		or	  r11, r4, r6
		sth	  r11, 0x66(r3)
		lhz	  r8, 0x68(r3)
		lbz	  r9, 0x68(r3)
		rotlwi	  r7, r8, 8
		or	  r6, r7, r9
		sth	  r6, 0x68(r3)
		lhz	  r11, 0x6A(r3)
		lbz	  r4, 0x6A(r3)
		rotlwi	  r10, r11, 8
		or	  r9, r10, r4
		sth	  r9, 0x6A(r3)
		lhz	  r6, 0x6C(r3)
		lbz	  r7, 0x6C(r3)
		rotlwi	  r5, r6, 8
		or	  r4, r5, r7
		sth	  r4, 0x6C(r3)
		lhz	  r9, 0x6E(r3)
		lbz	  r10, 0x6E(r3)
		rotlwi	  r8, r9, 8
		or	  r7, r8, r10
		sth	  r7, 0x6E(r3)
		lhz	  r5, 0x70(r3)
		rotlwi	  r4, r5, 8
		lbz	  r11, 0x70(r3)
		or	  r10, r4, r11
		sth	  r10, 0x70(r3)
		lhz	  r8, 0x72(r3)
		rotlwi	  r7, r8, 8
		lbz	  r6, 0x72(r3)
		or	  r5, r7, r6
		sth	  r5, 0x72(r3)
		lhz	  r10, 0x74(r3)
		rotlwi	  r9, r10, 8
		lbz	  r11, 0x74(r3)
		or	  r8, r9, r11
		sth	  r8, 0x74(r3)
		lhz	  r5, 0x76(r3)
		rotlwi	  r4, r5, 8
		lbz	  r6, 0x76(r3)
		or	  r11, r4, r6
		sth	  r11, 0x76(r3)
		lbz	  r9, 0x78(r3)
		lhz	  r8, 0x78(r3)
		rotlwi	  r7, r8, 8
		or	  r6, r7, r9
		sth	  r6, 0x78(r3)
		lbz	  r11, 0x7A(r3)
		lhz	  r4, 0x7A(r3)
		rotlwi	  r10, r4, 8
		or	  r9, r10, r11
		sth	  r9, 0x7A(r3)
		lhz	  r7, 0x7C(r3)
		rotlwi	  r6, r7, 8
		lbz	  r5, 0x7C(r3)
		or	  r4, r6, r5
		sth	  r4, 0x7C(r3)
		lbz	  r8, 0x7E(r3)
		lhz	  r10, 0x7E(r3)
		rotlwi	  r9, r10, 8
		or	  r7, r9, r8
		sth	  r7, 0x7E(r3)
		lhz	  r5, 0x80(r3)
		rotlwi	  r4, r5, 8
		lbz	  r11, 0x80(r3)
		or	  r10, r4, r11
		sth	  r10, 0x80(r3)
		lhz	  r8, 0x82(r3)
		rotlwi	  r7, r8, 8
		lbz	  r6, 0x82(r3)
		or	  r5, r7, r6
		sth	  r5, 0x82(r3)
		lhz	  r11, 0x84(r3)
		rotlwi	  r10, r11, 8
		lbz	  r9, 0x84(r3)
		or	  r8, r10, r9
		sth	  r8, 0x84(r3)
		lhz	  r6, 0x86(r3)
		lbz	  r4, 0x86(r3)
		rotlwi	  r5, r6, 8
		or	  r11, r5, r4
		sth	  r11, 0x86(r3)
		lbz	  r9, 0x88(r3)
		lhz	  r8, 0x88(r3)
		rotlwi	  r7, r8, 8
		or	  r6, r7, r9
		sth	  r6, 0x88(r3)
		lbz	  r4, 0x8A(r3)
		lhz	  r11, 0x8A(r3)
		rotlwi	  r10, r11, 8
		or	  r9, r10, r4
		sth	  r9, 0x8A(r3)
		lbz	  r5, 0x90(r3)
		lwz	  r7, 0x90(r3)
		mr	  r6, r7
		insrwi	  r6, r7, 16,0
		rlwinm	  r4, r7, 24,16,23
		extlwi	  r11, r6, 16,8
		or	  r10, r11, r4
		or	  r9, r10, r5
		stw	  r9, 0x90(r3)
		lbz	  r6, 0x94(r3)
		lwz	  r8, 0x94(r3)
		mr	  r7, r8
		insrwi	  r7, r8, 16,0
		rlwinm	  r5, r8, 24,16,23
		extlwi	  r4, r7, 16,8
		or	  r11, r4, r5
		or	  r10, r11, r6
		stw	  r10, 0x94(r3)
		blr
	}
}

void __declspec(naked) sub_82568170() {
	__asm {
		mfspr	r12, LR
		//bl	  __savegprlr_14
		std       r14, -0x98(r1)
		std       r15, -0x90(r1)
		std       r16, -0x88(r1)
		std       r17, -0x80(r1)
		std       r18, -0x78(r1)
		std       r19, -0x70(r1)
		std       r20, -0x68(r1)
		std       r21, -0x60(r1)
		std       r22, -0x58(r1)
		std       r23, -0x50(r1)
		std       r24, -0x48(r1)
		std       r25, -0x40(r1)
		std       r26, -0x38(r1)
		std       r27, -0x30(r1)
		std       r28, -0x28(r1)
		std       r29, -0x20(r1)
		std       r30, -0x18(r1)
		std       r31, -0x10(r1)
		stw       r12, -0x8(r1)

		stwu	  r1, -0x100(r1)
		lhz	  r10, 0(r3)
		mr	  r29, r4
		lbz	  r9, 0(r3)
		addi	  r11, r3, 2
		rotlwi	  r8, r10, 8
		or	  r7, r8, r9
		sth	  r7, 0(r3)
		lbz	  r5, 2(r3)
		lhz	  r4, 2(r3)
		rotlwi	  r10, r4, 8
		or	  r9, r10, r5
		sth	  r9, 2(r3)
		lhzu	  r7, 2(r11)
		rotlwi	  r6, r7, 8
		lbz	  r5, 0(r11)
		or	  r4, r6, r5
		sth	  r4, 0(r11)
		lhzu	  r10, 2(r11)
		rotlwi	  r9, r10, 8
		lbz	  r8, 0(r11)
		or	  r7, r9, r8
		sth	  r7, 0(r11)
		lhzu	  r5, 2(r11)
		rotlwi	  r4, r5, 8
		lbz	  r3, 0(r11)
		or	  r10, r4, r3
		sth	  r10, 0(r11)
		lhzu	  r8, 2(r11)
		rotlwi	  r7, r8, 8
		lbz	  r6, 0(r11)
		or	  r5, r7, r6
		sth	  r5, 0(r11)
		lwzu	  r10, 2(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r9, 0(r11)
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r9
		stw	  r5, 0(r11)
		lhzu	  r4, 4(r11)
		rotlwi	  r3, r4, 8
		lbz	  r10, 0(r11)
		or	  r9, r3, r10
		sth	  r9, 0(r11)
		lhzu	  r7, 2(r11)
		rotlwi	  r6, r7, 8
		lbz	  r5, 0(r11)
		or	  r4, r6, r5
		sth	  r4, 0(r11)
		lwzu	  r10, 2(r11)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		lbz	  r8, 0(r11)
		rlwinm	  r7, r10, 24,16,23
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r8
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r9, 0(r11)
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r9
		stw	  r5, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		insrwi	  r4, r10, 16,0
		lbz	  r9, 0(r11)
		rlwinm	  r3, r10, 24,16,23
		extlwi	  r10, r4, 16,8
		or	  r8, r10, r3
		or	  r7, r8, r9
		stw	  r7, 0(r11)
		lhzu	  r6, 4(r11)
		rotlwi	  r5, r6, 8
		lbz	  r4, 0(r11)
		or	  r3, r5, r4
		sth	  r3, 0(r11)
		lhzu	  r9, 2(r11)
		rotlwi	  r8, r9, 8
		lbz	  r7, 0(r11)
		or	  r6, r8, r7
		sth	  r6, 0(r11)
		lhzu	  r4, 2(r11)
		rotlwi	  r3, r4, 8
		lbz	  r10, 0(r11)
		or	  r9, r3, r10
		sth	  r9, 0(r11)
		lhzu	  r7, 2(r11)
		rotlwi	  r6, r7, 8
		lbz	  r5, 0(r11)
		or	  r4, r6, r5
		sth	  r4, 0(r11)
		lwzu	  r10, 2(r11)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		lbz	  r8, 0(r11)
		rlwinm	  r7, r10, 24,16,23
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r8
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r9, 0(r11)
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r9
		stw	  r5, 0(r11)
		lhzu	  r4, 4(r11)
		rotlwi	  r3, r4, 8
		lbz	  r10, 0(r11)
		or	  r9, r3, r10
		sth	  r9, 0(r11)
		lhzu	  r7, 2(r11)
		rotlwi	  r6, r7, 8
		lbz	  r5, 0(r11)
		or	  r4, r6, r5
		sth	  r4, 0(r11)
		lwzu	  r10, 0x42(r11)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		lbz	  r8, 0(r11)
		rlwinm	  r7, r10, 24,16,23
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r8
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r9, 0(r11)
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r9
		stw	  r5, 0(r11)
		li	  r9, 8
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		insrwi	  r4, r10, 16,0
		lbz	  r8, 0(r11)
		rlwinm	  r3, r10, 24,16,23
		mtspr	CTR, r9
		extlwi	  r10, r4, 16,8
		or	  r7, r10, r3
		or	  r6, r7, r8
		stw	  r6, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r5, r10
		insrwi	  r5, r10, 16,0
		lbz	  r3, 0(r11)
		rlwinm	  r4, r10, 24,16,23
		extlwi	  r10, r5, 16,8
		or	  r9, r10, r4
		or	  r8, r9, r3
		stw	  r8, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r7, r10
		rlwinm	  r6, r10, 24,16,23
		insrwi	  r7, r10, 16,0
		lbz	  r5, 0(r11)
		extlwi	  r4, r7, 16,8
		or	  r3, r4, r6
		or	  r10, r3, r5
		stw	  r10, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		lbz	  r8, 0(r11)
		rlwinm	  r7, r10, 24,16,23
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r8
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r9, 0(r11)
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r9
		stw	  r5, 0(r11)
		lwzu	  r10, 8(r11)
		mr	  r4, r10
		insrwi	  r4, r10, 16,0
		lbz	  r3, 0(r11)
		rlwinm	  r10, r10, 24,16,23
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r3
		stw	  r7, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r6, r10
		insrwi	  r6, r10, 16,0
		lbz	  r5, 0(r11)
		rlwinm	  r4, r10, 24,16,23
		extlwi	  r3, r6, 16,8
		or	  r10, r3, r4
		or	  r9, r10, r5
		stw	  r9, 0(r11)
		addi	  r11, r11, 4

loc_825684C4:				// CODE XREF: sub_82568170+3E8j
		lwz	  r10, 0(r11)
		lwz	  r9, 4(r11)
		lwz	  r8, 8(r11)
		mr	  r7, r10
		lwz	  r6, 0xC(r11)
		mr	  r5, r9
		insrwi	  r7, r10, 16,0
		lbz	  r3, 0(r11)
		mr	  r4, r8
		lbz	  r31, 4(r11)
		mr	  r30, r6
		lbz	  r28, 8(r11)
		insrwi	  r5, r9, 16,0
		lbz	  r27, 0xC(r11)
		insrwi	  r4, r8, 16,0
		rlwinm	  r10, r10, 24,16,23
		extlwi	  r7, r7, 16,8
		insrwi	  r30, r6, 16,0
		rlwinm	  r9, r9, 24,16,23
		extlwi	  r5, r5, 16,8
		or	  r7, r7, r10
		rlwinm	  r8, r8, 24,16,23
		extlwi	  r4, r4, 16,8
		extlwi	  r10, r30, 16,8
		rlwinm	  r6, r6, 24,16,23
		or	  r5, r5, r9
		or	  r4, r4, r8
		or	  r3, r7, r3
		or	  r10, r10, r6
		or	  r9, r5, r31
		stw	  r3, 0(r11)
		or	  r8, r4, r28
		or	  r7, r10, r27
		stw	  r9, 4(r11)
		stw	  r8, 8(r11)
		stw	  r7, 0xC(r11)
		addi	  r11, r11, 0x10
		bdnz	  loc_825684C4
		lwz	  r10, 0(r11)
		lbz	  r9, 0(r11)
		mr	  r8, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r9
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r9, 0(r11)
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r9
		stw	  r5, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		insrwi	  r4, r10, 16,0
		rlwinm	  r10, r10, 24,16,23
		lbz	  r3, 0(r11)
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r3
		stw	  r7, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r6, r10
		rlwinm	  r5, r10, 24,16,23
		insrwi	  r6, r10, 16,0
		lbz	  r4, 0(r11)
		extlwi	  r3, r6, 16,8
		or	  r10, r3, r5
		or	  r9, r10, r4
		stw	  r9, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r8, r10
		insrwi	  r8, r10, 16,0
		lbz	  r7, 0(r11)
		rlwinm	  r6, r10, 24,16,23
		extlwi	  r5, r8, 16,8
		or	  r4, r5, r6
		or	  r3, r4, r7
		stw	  r3, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		lbz	  r8, 0(r11)
		rlwinm	  r7, r10, 24,16,23
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r8
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r9, 0(r11)
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r9
		stw	  r5, 0(r11)
		lhzu	  r4, 4(r11)
		rotlwi	  r3, r4, 8
		lbz	  r10, 0(r11)
		or	  r9, r3, r10
		sth	  r9, 0(r11)
		lwzu	  r10, 0xAC(r11)
		mr	  r7, r10
		insrwi	  r7, r10, 16,0
		lbz	  r5, 0(r11)
		rlwinm	  r6, r10, 24,16,23
		extlwi	  r4, r7, 16,8
		or	  r3, r4, r6
		or	  r10, r3, r5
		stw	  r10, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		lbz	  r8, 0(r11)
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r9, r10, 16,0
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r8
		stw	  r4, 0(r11)
		lhzu	  r3, 4(r11)
		rotlwi	  r10, r3, 8
		lbz	  r9, 0(r11)
		or	  r8, r10, r9
		sth	  r8, 0(r11)
		lhzu	  r6, 2(r11)
		rotlwi	  r5, r6, 8
		lbz	  r4, 0(r11)
		or	  r3, r5, r4
		sth	  r3, 0(r11)
		lhzu	  r9, 2(r11)
		rotlwi	  r8, r9, 8
		lbz	  r7, 0(r11)
		or	  r6, r8, r7
		sth	  r6, 0(r11)
		lhzu	  r4, 2(r11)
		rotlwi	  r3, r4, 8
		lbz	  r10, 0(r11)
		or	  r9, r3, r10
		sth	  r9, 0(r11)
		lhzu	  r7, 2(r11)
		rotlwi	  r6, r7, 8
		lbz	  r5, 0(r11)
		or	  r4, r6, r5
		sth	  r4, 0(r11)
		lhzu	  r10, 2(r11)
		rotlwi	  r9, r10, 8
		lbz	  r8, 0(r11)
		or	  r7, r9, r8
		sth	  r7, 0(r11)
		lwzu	  r10, 2(r11)
		mr	  r5, r10
		insrwi	  r5, r10, 16,0
		lbz	  r4, 0(r11)
		rlwinm	  r3, r10, 24,16,23
		extlwi	  r10, r5, 16,8
		or	  r9, r10, r3
		or	  r8, r9, r4
		stw	  r8, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r7, r10
		insrwi	  r7, r10, 16,0
		lbz	  r6, 0(r11)
		rlwinm	  r5, r10, 24,16,23
		extlwi	  r4, r7, 16,8
		or	  r3, r4, r5
		or	  r10, r3, r6
		stw	  r10, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		lbz	  r8, 0(r11)
		rlwinm	  r7, r10, 24,16,23
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r8
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r9, 0(r11)
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r9
		stw	  r5, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		insrwi	  r4, r10, 16,0
		lbz	  r3, 0(r11)
		rlwinm	  r9, r10, 24,16,23
		extlwi	  r8, r4, 16,8
		or	  r7, r8, r9
		or	  r6, r7, r3
		stw	  r6, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r5, r10
		lbz	  r4, 0(r11)
		rlwinm	  r3, r10, 24,16,23
		insrwi	  r5, r10, 16,0
		extlwi	  r10, r5, 16,8
		or	  r9, r10, r3
		or	  r8, r9, r4
		stw	  r8, 0(r11)
		lhzu	  r7, 4(r11)
		rotlwi	  r6, r7, 8
		lhz	  r7, 2(r11)
		addi	  r10, r11, 2
		lbz	  r27, 0(r11)
		addi	  r10, r11, 4
		lbz	  r28, 2(r11)
		addi	  r10, r11, 6
		lhz	  r30, 8(r11)
		addi	  r10, r11, 8
		lhz	  r3, 0xC(r11)
		addi	  r10, r11, 0xA
		lhz	  r25, 0xE(r11)
		addi	  r10, r11, 0xC
		lbz	  r9, 0xC(r11)
		addi	  r10, r11, 0xE
		lhz	  r24, 0x10(r11)
		addi	  r10, r11, 0x10
		lhz	  r31, 4(r11)
		addi	  r10, r11, 0x12
		lhz	  r5, 6(r11)
		rotlwi	  r31, r31, 8
		lbz	  r26, 6(r11)
		rotlwi	  r5, r5, 8
		lbz	  r4, 4(r11)
		or	  r4, r31, r4
		lbz	  r8, 0xE(r11)
		rotlwi	  r7, r7, 8
		lbz	  r31, 0xA(r11)
		or	  r6, r6, r27
		lhz	  r27, 0xA(r11)
		or	  r7, r7, r28
		lbz	  r28, 8(r11)
		rotlwi	  r30, r30, 8
		sth	  r6, 0(r11)
		rotlwi	  r27, r27, 8
		sth	  r7, 2(r11)
		rotlwi	  r3, r3, 8
		sth	  r4, 4(r11)
		or	  r5, r5, r26
		lbz	  r10, 0x12(r11)
		or	  r7, r27, r31
		sth	  r5, 6(r11)
		or	  r4, r3, r9
		or	  r6, r30, r28
		lhz	  r5, 0x12(r11)
		rotlwi	  r30, r25, 8
		lbz	  r3, 0x10(r11)
		sth	  r6, 8(r11)
		or	  r9, r30, r8
		sth	  r7, 0xA(r11)
		sth	  r4, 0xC(r11)
		rotlwi	  r4, r24, 8
		sth	  r9, 0xE(r11)
		rotlwi	  r9, r5, 8
		or	  r8, r4, r3
		or	  r7, r9, r10
		sth	  r8, 0x10(r11)
		sth	  r7, 0x12(r11)
		lwzu	  r10, 0x14(r11)
		mr	  r4, r10
		insrwi	  r4, r10, 16,0
		lwz	  r9, 0x14(r11)
		rlwinm	  r3, r10, 24,16,23
		lbz	  r8, 0(r11)
		extlwi	  r7, r4, 16,8
		lbz	  r6, 0x10(r11)
		addi	  r10, r11, 0x14
		lwz	  r5, 0x1C(r11)
		addi	  r10, r11, 0x18
		lwz	  r10, 4(r11)
		or	  r4, r7, r3
		lwz	  r3, 8(r11)
		mr	  r7, r10
		lwz	  r28, 0x10(r11)
		mr	  r30, r3
		lwz	  r31, 0xC(r11)
		insrwi	  r7, r10, 16,0
		lbz	  r26, 4(r11)
		mr	  r25, r28
		lbz	  r24, 8(r11)
		insrwi	  r30, r3, 16,0
		lwz	  r21, 0x18(r11)
		rlwinm	  r10, r10, 24,16,23
		lbz	  r22, 0xC(r11)
		extlwi	  r7, r7, 16,8
		lbz	  r20, 0x14(r11)
		mr	  r27, r31
		lwz	  r19, 0x20(r11)
		insrwi	  r25, r28, 16,0
		lwz	  r18, 0x24(r11)
		rlwinm	  r3, r3, 24,16,23
		extlwi	  r30, r30, 16,8
		or	  r10, r7, r10
		or	  r8, r4, r8
		mr	  r23, r9
		insrwi	  r27, r31, 16,0
		stw	  r8, 0(r11)
		extlwi	  r7, r25, 16,8
		rlwinm	  r28, r28, 24,16,23
		or	  r3, r30, r3
		insrwi	  r23, r9, 16,0
		rlwinm	  r31, r31, 24,16,23
		extlwi	  r27, r27, 16,8
		or	  r10, r10, r26
		or	  r8, r7, r28
		or	  r7, r3, r24
		stw	  r10, 4(r11)
		rlwinm	  r9, r9, 24,16,23
		or	  r4, r27, r31
		stw	  r7, 8(r11)
		extlwi	  r30, r23, 16,8
		lbz	  r31, 0x20(r11)
		or	  r10, r4, r22
		or	  r3, r30, r9
		lbz	  r30, 0x24(r11)
		mr	  r7, r21
		stw	  r10, 0xC(r11)
		or	  r9, r8, r6
		or	  r8, r3, r20
		insrwi	  r7, r21, 16,0
		stw	  r9, 0x10(r11)
		mr	  r4, r5
		stw	  r8, 0x14(r11)
		mr	  r3, r19
		lbz	  r9, 0x18(r11)
		mr	  r10, r18
		lbz	  r8, 0x1C(r11)
		insrwi	  r4, r5, 16,0
		rlwinm	  r6, r21, 24,16,23
		extlwi	  r7, r7, 16,8
		insrwi	  r10, r18, 16,0
		insrwi	  r3, r19, 16,0
		or	  r7, r7, r6
		extlwi	  r4, r4, 16,8
		rlwinm	  r5, r5, 24,16,23
		extlwi	  r6, r10, 16,8
		extlwi	  r3, r3, 16,8
		rlwinm	  r28, r19, 24,16,23
		rlwinm	  r10, r18, 24,16,23
		or	  r5, r4, r5
		or	  r4, r3, r28
		or	  r10, r6, r10
		or	  r3, r7, r9
		or	  r9, r5, r8
		or	  r8, r4, r31
		stw	  r3, 0x18(r11)
		or	  r7, r10, r30
		stw	  r9, 0x1C(r11)
		addi	  r10, r11, 0x1C
		stw	  r8, 0x20(r11)
		addi	  r10, r11, 0x20
		stw	  r7, 0x24(r11)
		addi	  r10, r11, 0x24
		lhzu	  r6, 0x28(r11)
		rotlwi	  r5, r6, 8
		lbz	  r30, 0(r11)
		lhz	  r7, 4(r11)
		lhz	  r4, 2(r11)
		or	  r5, r5, r30
		lbz	  r30, 4(r11)
		rotlwi	  r7, r7, 8
		lbz	  r31, 2(r11)
		rotlwi	  r4, r4, 8
		lhz	  r6, 6(r11)
		or	  r7, r7, r30
		lhz	  r3, 8(r11)
		or	  r4, r4, r31
		sth	  r5, 0(r11)
		rotlwi	  r6, r6, 8
		lbz	  r10, 6(r11)
		rotlwi	  r3, r3, 8
		sth	  r4, 2(r11)
		mr	  r4, r7
		lbz	  r28, 8(r11)
		or	  r10, r6, r10
		lhz	  r27, 0xA(r11)
		lhz	  r8, 0xC(r11)
		or	  r3, r3, r28
		sth	  r4, 4(r11)
		rotlwi	  r28, r27, 8
		lbz	  r9, 0xA(r11)
		rotlwi	  r8, r8, 8
		lhz	  r31, 0xE(r11)
		sth	  r10, 6(r11)
		or	  r4, r28, r9
		lhz	  r30, 0x10(r11)
		lbz	  r26, 0xC(r11)
		sth	  r3, 8(r11)
		rotlwi	  r3, r31, 8
		lhz	  r6, 0x12(r11)
		or	  r9, r8, r26
		lbz	  r5, 0xE(r11)
		rotlwi	  r10, r30, 8
		lbz	  r7, 0x10(r11)
		rotlwi	  r8, r6, 8
		lbz	  r27, 0x12(r11)
		or	  r6, r3, r5
		sth	  r4, 0xA(r11)
		or	  r5, r10, r7
		sth	  r9, 0xC(r11)
		or	  r3, r8, r27
		sth	  r6, 0xE(r11)
		sth	  r5, 0x10(r11)
		sth	  r3, 0x12(r11)
		lhzu	  r7, 0x14(r11)
		rotlwi	  r6, r7, 8
		lbz	  r24, 0(r11)
		lhz	  r27, 4(r11)
		lhz	  r22, 0x10(r11)
		lhz	  r28, 2(r11)
		lhz	  r26, 6(r11)
		lbz	  r23, 6(r11)
		rotlwi	  r28, r28, 8
		rotlwi	  r26, r26, 8
		lhz	  r5, 8(r11)
		lbz	  r25, 2(r11)
		or	  r28, r28, r25
		or	  r6, r6, r24
		lhz	  r4, 0xA(r11)
		or	  r26, r26, r23
		lbz	  r3, 4(r11)
		lhz	  r10, 0xC(r11)
		rotlwi	  r27, r27, 8
		lhz	  r9, 0xE(r11)
		rotlwi	  r22, r22, 8
		lhz	  r8, 0x12(r11)
		rotlwi	  r5, r5, 8
		lbz	  r7, 0xE(r11)
		lbz	  r31, 0x10(r11)
		lbz	  r30, 0x12(r11)
		lbz	  r25, 8(r11)
		lbz	  r24, 0xA(r11)
		lbz	  r23, 0xC(r11)
		sth	  r6, 0(r11)
		or	  r3, r27, r3
		sth	  r28, 2(r11)
		rotlwi	  r6, r4, 8
		std	  r29, 0x60(r1)
		rotlwi	  r4, r10, 8
		or	  r10, r5, r25
		mr	  r5, r3
		or	  r3, r6, r24
		rotlwi	  r9, r9, 8
		sth	  r5, 4(r11)
		or	  r6, r4, r23
		sth	  r26, 6(r11)
		rotlwi	  r4, r8, 8
		sth	  r10, 8(r11)
		or	  r9, r9, r7
		sth	  r3, 0xA(r11)
		or	  r7, r22, r31
		sth	  r6, 0xC(r11)
		or	  r5, r4, r30
		sth	  r9, 0xE(r11)
		sth	  r7, 0x10(r11)
		sth	  r5, 0x12(r11)
		lwzu	  r10, 0x14(r11)
		mr	  r9, r10
		lwz	  r4, 8(r11)
		insrwi	  r9, r10, 16,0
		lwz	  r8, 4(r11)
		rlwinm	  r10, r10, 24,16,23
		lwz	  r3, 0xC(r11)
		extlwi	  r9, r9, 16,8
		lwz	  r28, 0x14(r11)
		lwz	  r31, 0x10(r11)
		or	  r10, r9, r10
		lbz	  r29, 0x20(r11)
		lwz	  r26, 0x18(r11)
		lwz	  r25, 0x1C(r11)
		lbz	  r7, 0(r11)
		lwz	  r21, 0x24(r11)
		lbz	  r14, 0x1C(r11)
		lwz	  r23, 0x20(r11)
		stw	  r14, 0x50(r1)
		mr	  r30, r4
		lbz	  r14, 0x24(r11)
		mr	  r6, r8
		stw	  r29, 0x54(r1)
		mr	  r27, r3
		stw	  r14, 0x58(r1)
		insrwi	  r30, r4, 16,0
		lbz	  r5, 0x10(r11)
		insrwi	  r6, r8, 16,0
		lbz	  r20, 4(r11)
		insrwi	  r27, r3, 16,0
		lbz	  r19, 8(r11)
		mr	  r24, r31
		lbz	  r18, 0xC(r11)
		mr	  r22, r28
		lbz	  r16, 0x14(r11)
		extlwi	  r30, r30, 16,8
		lbz	  r15, 0x18(r11)
		rlwinm	  r4, r4, 24,16,23
		extlwi	  r6, r6, 16,8
		rlwinm	  r8, r8, 24,16,23
		insrwi	  r24, r31, 16,0
		extlwi	  r9, r27, 16,8
		mr	  r17, r26
		mr	  r29, r25
		insrwi	  r22, r28, 16,0
		mr	  r14, r23
		rlwinm	  r3, r3, 24,16,23
		or	  r4, r30, r4
		or	  r8, r6, r8
		rlwinm	  r30, r28, 24,16,23
		insrwi	  r17, r26, 16,0
		mr	  r27, r21
		extlwi	  r6, r24, 16,8
		rlwinm	  r31, r31, 24,16,23
		insrwi	  r29, r25, 16,0
		extlwi	  r28, r22, 16,8
		insrwi	  r14, r23, 16,0
		or	  r10, r10, r7
		or	  r9, r9, r3
		stw	  r10, 0(r11)
		or	  r10, r8, r20
		or	  r8, r6, r31
		or	  r4, r4, r19
		stw	  r10, 4(r11)
		or	  r9, r9, r18
		or	  r8, r8, r5
		stw	  r4, 8(r11)
		rlwinm	  r3, r26, 24,16,23
		stw	  r9, 0xC(r11)
		extlwi	  r7, r17, 16,8
		stw	  r8, 0x10(r11)
		rlwinm	  r10, r25, 24,16,23
		lwz	  r8, 0x50(r1)
		extlwi	  r6, r29, 16,8
		or	  r7, r7, r3
		or	  r6, r6, r10
		or	  r31, r28, r30
		extlwi	  r30, r14, 16,8
		rlwinm	  r4, r23, 24,16,23
		or	  r10, r7, r15
		insrwi	  r27, r21, 16,0
		or	  r7, r6, r8
		lwz	  r6, 0x54(r1)
		or	  r5, r31, r16
		or	  r4, r30, r4
		extlwi	  r3, r27, 16,8
		stw	  r5, 0x14(r11)
		rlwinm	  r9, r21, 24,16,23
		stw	  r10, 0x18(r11)
		or	  r5, r4, r6
		lwz	  r4, 0x58(r1)
		or	  r9, r3, r9
		stw	  r7, 0x1C(r11)
		stw	  r5, 0x20(r11)
		or	  r3, r9, r4
		stw	  r3, 0x24(r11)
		lwzu	  r10, 0x28(r11)
		mr	  r9, r10
		lwz	  r6, 8(r11)
		insrwi	  r9, r10, 16,0
		lwz	  r30, 0x14(r11)
		rlwinm	  r8, r10, 24,16,23
		lwz	  r28, 0x18(r11)
		extlwi	  r5, r9, 16,8
		lwz	  r7, 4(r11)
		mr	  r3, r7
		lwz	  r4, 0xC(r11)
		insrwi	  r3, r7, 16,0
		lwz	  r10, 0x10(r11)
		mr	  r9, r6
		mr	  r31, r4
		lwz	  r26, 0x1C(r11)
		rlwinm	  r7, r7, 24,16,23
		lwz	  r25, 0x20(r11)
		extlwi	  r3, r3, 16,8
		lbz	  r24, 0(r11)
		insrwi	  r9, r6, 16,0
		lwz	  r23, 0x24(r11)
		insrwi	  r31, r4, 16,0
		lbz	  r22, 4(r11)
		mr	  r27, r10
		lbz	  r21, 8(r11)
		mr	  r20, r30
		lbz	  r19, 0xC(r11)
		or	  r8, r5, r8
		lbz	  r17, 0x10(r11)
		or	  r3, r3, r7
		lbz	  r16, 0x14(r11)
		lbz	  r15, 0x18(r11)
		insrwi	  r27, r10, 16,0
		lbz	  r5, 0x1C(r11)
		mr	  r18, r28
		lbz	  r14, 0x20(r11)
		rlwinm	  r6, r6, 24,16,23
		lbz	  r29, 0x24(r11)
		extlwi	  r9, r9, 16,8
		extlwi	  r31, r31, 16,8
		rlwinm	  r4, r4, 24,16,23
		mr	  r7, r26
		insrwi	  r20, r30, 16,0
		stw	  r29, 0x58(r1)
		or	  r9, r9, r6
		or	  r6, r31, r4
		or	  r8, r8, r24
		or	  r4, r3, r22
		rlwinm	  r10, r10, 24,16,23
		stw	  r8, 0(r11)
		extlwi	  r27, r27, 16,8
		stw	  r4, 4(r11)
		or	  r9, r9, r21
		insrwi	  r18, r28, 16,0
		or	  r10, r27, r10
		stw	  r9, 8(r11)
		insrwi	  r7, r26, 16,0
		mr	  r29, r25
		mr	  r3, r23
		rlwinm	  r4, r30, 24,16,23
		or	  r6, r6, r19
		rlwinm	  r30, r28, 24,16,23
		extlwi	  r8, r20, 16,8
		stw	  r6, 0xC(r11)
		extlwi	  r31, r18, 16,8
		extlwi	  r9, r7, 16,8
		or	  r10, r10, r17
		insrwi	  r3, r23, 16,0
		insrwi	  r29, r25, 16,0
		stw	  r10, 0x10(r11)
		rlwinm	  r7, r26, 24,16,23
		or	  r6, r8, r4
		or	  r31, r31, r30
		extlwi	  r3, r3, 16,8
		extlwi	  r4, r29, 16,8
		rlwinm	  r8, r25, 24,16,23
		rlwinm	  r30, r23, 24,16,23
		or	  r10, r9, r7
		or	  r9, r6, r16
		or	  r6, r3, r30
		lwz	  r3, 0x58(r1)
		or	  r8, r4, r8
		stw	  r9, 0x14(r11)
		or	  r7, r31, r15
		or	  r5, r10, r5
		or	  r4, r8, r14
		stw	  r7, 0x18(r11)
		or	  r10, r6, r3
		stw	  r5, 0x1C(r11)
		stw	  r4, 0x20(r11)
		stw	  r10, 0x24(r11)
		lhzu	  r9, 0x28(r11)
		rotlwi	  r8, r9, 8
		lbz	  r28, 0(r11)
		lhz	  r10, 4(r11)
		or	  r8, r8, r28
		lbz	  r28, 4(r11)
		rotlwi	  r10, r10, 8
		lhz	  r30, 8(r11)
		lbz	  r27, 6(r11)
		or	  r10, r10, r28
		lbz	  r28, 8(r11)
		lhz	  r3, 2(r11)
		lhz	  r9, 6(r11)
		rotlwi	  r3, r3, 8
		lbz	  r31, 2(r11)
		rotlwi	  r9, r9, 8
		lhz	  r7, 0xC(r11)
		or	  r3, r3, r31
		lhz	  r31, 0xA(r11)
		lhz	  r26, 0xE(r11)
		rotlwi	  r30, r30, 8
		or	  r9, r9, r27
		sth	  r8, 0(r11)
		lbz	  r6, 0xA(r11)
		rotlwi	  r31, r31, 8
		lhz	  r5, 0x10(r11)
		rotlwi	  r7, r7, 8
		lbz	  r4, 0xC(r11)
		or	  r30, r30, r28
		lhz	  r25, 0x12(r11)
		rotlwi	  r8, r26, 8
		lbz	  r27, 0xE(r11)
		lbz	  r24, 0x10(r11)
		sth	  r3, 2(r11)
		mr	  r3, r9
		sth	  r10, 4(r11)
		or	  r6, r31, r6
		sth	  r3, 6(r11)
		rotlwi	  r5, r5, 8
		lbz	  r28, 0x12(r11)
		or	  r10, r7, r4
		sth	  r30, 8(r11)
		rotlwi	  r9, r25, 8
		sth	  r6, 0xA(r11)
		or	  r4, r8, r27
		sth	  r10, 0xC(r11)
		or	  r8, r5, r24
		or	  r6, r9, r28
		sth	  r4, 0xE(r11)
		sth	  r8, 0x10(r11)
		sth	  r6, 0x12(r11)
		lhzu	  r10, 0x14(r11)
		rotlwi	  r9, r10, 8
		lhz	  r6, 4(r11)
		lhz	  r5, 6(r11)
		lbz	  r8, 0(r11)
		lhz	  r7, 2(r11)
		rotlwi	  r4, r7, 8
		rotlwi	  r10, r6, 8
		lbz	  r7, 4(r11)
		rotlwi	  r6, r5, 8
		lbz	  r3, 2(r11)
		or	  r5, r9, r8
		lbz	  r27, 0xC(r11)
		or	  r8, r4, r3
		lbz	  r25, 0x10(r11)
		or	  r3, r10, r7
		lbz	  r10, 6(r11)
		lhz	  r9, 8(r11)
		lbz	  r31, 8(r11)
		lhz	  r4, 0xA(r11)
		rotlwi	  r9, r9, 8
		rotlwi	  r4, r4, 8
		lhz	  r7, 0xC(r11)
		or	  r10, r6, r10
		lbz	  r6, 0xA(r11)
		sth	  r5, 0(r11)
		or	  r9, r9, r31
		lhz	  r30, 0xE(r11)
		or	  r6, r4, r6
		sth	  r8, 2(r11)
		rotlwi	  r7, r7, 8
		lhz	  r28, 0x10(r11)
		rotlwi	  r30, r30, 8
		sth	  r3, 4(r11)
		mr	  r3, r9
		lhz	  r31, 0x12(r11)
		mr	  r9, r6
		lbz	  r26, 0xE(r11)
		rotlwi	  r4, r28, 8
		sth	  r10, 6(r11)
		or	  r7, r7, r27
		lbz	  r5, 0x12(r11)
		rotlwi	  r8, r31, 8
		sth	  r3, 8(r11)
		or	  r10, r30, r26
		sth	  r9, 0xA(r11)
		or	  r6, r4, r25
		sth	  r7, 0xC(r11)
		or	  r3, r8, r5
		sth	  r10, 0xE(r11)
		sth	  r6, 0x10(r11)
		sth	  r3, 0x12(r11)
		lwzu	  r10, 0x14(r11)
		mr	  r7, r10
		insrwi	  r7, r10, 16,0
		lbz	  r5, 0(r11)
		rlwinm	  r6, r10, 24,16,23
		extlwi	  r4, r7, 16,8
		or	  r3, r4, r6
		or	  r10, r3, r5
		stw	  r10, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		lbz	  r7, 0(r11)
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r8
		or	  r4, r5, r7
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r9, 0(r11)
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r9
		stw	  r5, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		rlwinm	  r3, r10, 24,16,23
		insrwi	  r4, r10, 16,0
		lbz	  r10, 0(r11)
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r3
		or	  r7, r8, r10
		stw	  r7, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r6, r10
		rlwinm	  r4, r10, 24,16,23
		insrwi	  r6, r10, 16,0
		lbz	  r5, 0(r11)
		extlwi	  r3, r6, 16,8
		or	  r10, r3, r4
		or	  r9, r10, r5
		stw	  r9, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r8, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		lbz	  r6, 0(r11)
		extlwi	  r5, r8, 16,8
		or	  r4, r5, r7
		or	  r3, r4, r6
		stw	  r3, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		rlwinm	  r8, r10, 24,16,23
		insrwi	  r9, r10, 16,0
		lbz	  r7, 0(r11)
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r8
		or	  r4, r5, r7
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		rlwinm	  r9, r10, 24,16,23
		insrwi	  r3, r10, 16,0
		lbz	  r8, 0(r11)
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		rlwinm	  r3, r10, 24,16,23
		insrwi	  r4, r10, 16,0
		lbz	  r10, 0(r11)
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r3
		or	  r7, r8, r10
		stw	  r7, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r6, r10
		insrwi	  r6, r10, 16,0
		lbz	  r4, 0(r11)
		rlwinm	  r5, r10, 24,16,23
		extlwi	  r3, r6, 16,8
		or	  r10, r3, r5
		or	  r9, r10, r4
		stw	  r9, 0(r11)
		lhzu	  r8, 8(r11)
		rotlwi	  r7, r8, 8
		lbz	  r6, 0(r11)
		or	  r5, r7, r6
		sth	  r5, 0(r11)
		lhzu	  r3, 2(r11)
		rotlwi	  r10, r3, 8
		lbz	  r9, 0(r11)
		or	  r8, r10, r9
		sth	  r8, 0(r11)
		lwzu	  r10, 2(r11)
		mr	  r6, r10
		insrwi	  r6, r10, 16,0
		lbz	  r4, 0(r11)
		rlwinm	  r5, r10, 24,16,23
		extlwi	  r3, r6, 16,8
		or	  r10, r3, r5
		or	  r9, r10, r4
		stw	  r9, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r8, r10
		insrwi	  r8, r10, 16,0
		lbz	  r7, 0(r11)
		rlwinm	  r6, r10, 24,16,23
		extlwi	  r5, r8, 16,8
		or	  r4, r5, r6
		or	  r3, r4, r7
		stw	  r3, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r9, r10, 16,0
		lbz	  r8, 0(r11)
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r8
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		rlwinm	  r9, r10, 24,16,23
		insrwi	  r3, r10, 16,0
		lbz	  r8, 0(r11)
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		rlwinm	  r3, r10, 24,16,23
		insrwi	  r4, r10, 16,0
		lbz	  r10, 0(r11)
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r3
		or	  r7, r8, r10
		stw	  r7, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r6, r10
		rlwinm	  r5, r10, 24,16,23
		insrwi	  r6, r10, 16,0
		lbz	  r4, 0(r11)
		extlwi	  r3, r6, 16,8
		or	  r10, r3, r5
		or	  r9, r10, r4
		stw	  r9, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r8, r10
		insrwi	  r8, r10, 16,0
		lbz	  r6, 0(r11)
		rlwinm	  r7, r10, 24,16,23
		extlwi	  r5, r8, 16,8
		or	  r4, r5, r7
		or	  r3, r4, r6
		stw	  r3, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		lbz	  r7, 0(r11)
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r8
		or	  r4, r5, r7
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		lbz	  r8, 0(r11)
		rlwinm	  r9, r10, 24,16,23
		insrwi	  r3, r10, 16,0
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		rlwinm	  r3, r10, 24,16,23
		insrwi	  r4, r10, 16,0
		lbz	  r10, 0(r11)
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r3
		or	  r7, r8, r10
		stw	  r7, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r6, r10
		insrwi	  r6, r10, 16,0
		lbz	  r5, 0(r11)
		rlwinm	  r4, r10, 24,16,23
		extlwi	  r3, r6, 16,8
		or	  r10, r3, r4
		or	  r9, r10, r5
		stw	  r9, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r8, r10
		rlwinm	  r6, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		lbz	  r7, 0(r11)
		extlwi	  r5, r8, 16,8
		or	  r4, r5, r6
		or	  r3, r4, r7
		stw	  r3, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		rlwinm	  r8, r10, 24,16,23
		insrwi	  r9, r10, 16,0
		lbz	  r7, 0(r11)
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r8
		or	  r4, r5, r7
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		rlwinm	  r9, r10, 24,16,23
		insrwi	  r3, r10, 16,0
		lbz	  r8, 0(r11)
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0(r11)
		lhzu	  r4, 4(r11)
		rotlwi	  r3, r4, 8
		lbz	  r10, 0(r11)
		or	  r9, r3, r10
		sth	  r9, 0(r11)
		lhzu	  r7, 2(r11)
		rotlwi	  r6, r7, 8
		lbz	  r5, 0(r11)
		or	  r4, r6, r5
		sth	  r4, 0(r11)
		lwzu	  r10, 6(r11)
		mr	  r9, r10
		insrwi	  r9, r10, 16,0
		lbz	  r7, 0(r11)
		rlwinm	  r8, r10, 24,16,23
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r8
		or	  r4, r5, r7
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r8, 0(r11)
		rlwinm	  r9, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		rlwinm	  r3, r10, 24,16,23
		insrwi	  r4, r10, 16,0
		lbz	  r10, 0(r11)
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r3
		or	  r7, r8, r10
		stw	  r7, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r6, r10
		insrwi	  r6, r10, 16,0
		lbz	  r4, 0(r11)
		rlwinm	  r5, r10, 24,16,23
		extlwi	  r3, r6, 16,8
		or	  r10, r3, r5
		or	  r9, r10, r4
		stw	  r9, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r8, r10
		insrwi	  r8, r10, 16,0
		lbz	  r6, 0(r11)
		rlwinm	  r7, r10, 24,16,23
		extlwi	  r5, r8, 16,8
		or	  r4, r5, r7
		or	  r3, r4, r6
		stw	  r3, 0(r11)
		lhzu	  r10, 4(r11)
		rotlwi	  r9, r10, 8
		lbz	  r8, 0(r11)
		or	  r7, r9, r8
		sth	  r7, 0(r11)
		lhzu	  r5, 2(r11)
		rotlwi	  r4, r5, 8
		lbz	  r3, 0(r11)
		or	  r10, r4, r3
		sth	  r10, 0(r11)
		lwzu	  r10, 2(r11)
		mr	  r8, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		lbz	  r6, 0(r11)
		extlwi	  r5, r8, 16,8
		or	  r4, r5, r7
		or	  r3, r4, r6
		stw	  r3, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r9, r10, 16,0
		lbz	  r8, 0(r11)
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r8
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		rlwinm	  r9, r10, 24,16,23
		insrwi	  r3, r10, 16,0
		lbz	  r8, 0(r11)
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		insrwi	  r4, r10, 16,0
		rlwinm	  r3, r10, 24,16,23
		lbz	  r10, 0(r11)
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r3
		or	  r7, r8, r10
		stw	  r7, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r6, r10
		rlwinm	  r4, r10, 24,16,23
		insrwi	  r6, r10, 16,0
		lbz	  r5, 0(r11)
		extlwi	  r3, r6, 16,8
		or	  r10, r3, r4
		or	  r9, r10, r5
		stw	  r9, 0(r11)
		lhzu	  r8, 4(r11)
		rotlwi	  r7, r8, 8
		lbz	  r6, 0(r11)
		or	  r5, r7, r6
		sth	  r5, 0(r11)
		lhzu	  r3, 2(r11)
		rotlwi	  r10, r3, 8
		lbz	  r9, 0(r11)
		or	  r8, r10, r9
		sth	  r8, 0(r11)
		lhzu	  r6, 2(r11)
		rotlwi	  r5, r6, 8
		lbz	  r4, 0(r11)
		or	  r3, r5, r4
		sth	  r3, 0(r11)
		lhzu	  r9, 2(r11)
		rotlwi	  r8, r9, 8
		lbz	  r7, 0(r11)
		or	  r6, r8, r7
		sth	  r6, 0(r11)
		lwzu	  r10, 2(r11)
		mr	  r4, r10
		insrwi	  r4, r10, 16,0
		lwz	  r8, 8(r11)
		rlwinm	  r3, r10, 24,16,23
		lwz	  r10, 4(r11)
		lwz	  r6, 0xC(r11)
		extlwi	  r7, r4, 16,8
		mr	  r5, r10
		lbz	  r31, 0(r11)
		mr	  r4, r8
		lbz	  r28, 4(r11)
		mr	  r30, r6
		lbz	  r27, 8(r11)
		insrwi	  r5, r10, 16,0
		lbz	  r26, 0xC(r11)
		insrwi	  r4, r8, 16,0
		insrwi	  r30, r6, 16,0
		rlwinm	  r10, r10, 24,16,23
		extlwi	  r5, r5, 16,8
		or	  r7, r7, r3
		extlwi	  r4, r4, 16,8
		rlwinm	  r8, r8, 24,16,23
		rlwinm	  r6, r6, 24,16,23
		extlwi	  r3, r30, 16,8
		or	  r5, r5, r10
		or	  r4, r4, r8
		or	  r8, r3, r6
		or	  r10, r7, r31
		addi	  r9, r11, 0xC
		or	  r7, r5, r28
		stw	  r10, 0(r11)
		or	  r6, r4, r27
		or	  r5, r8, r26
		stw	  r7, 4(r11)
		stw	  r6, 8(r11)
		addi	  r11, r11, 0x50
		stw	  r5, 0(r9)
		addi	  r4, r11, 7
		clrrwi	  r3, r4, 3
		ld	  r10, 0x10(r3)
		lbz	  r9, 0x16(r3)
		sldi	  r8, r10, 8
		lbz	  r10, 0x12(r3)
		lbz	  r7, 0x15(r3)
		or	  r5, r9, r8
		lbz	  r8, 0x11(r3)
		sldi	  r9, r5, 8
		lbz	  r6, 0x14(r3)
		lbz	  r4, 0x13(r3)
		or	  r9, r9, r7
		lbz	  r5, 0x10(r3)
		sldi	  r7, r9, 8
		or	  r6, r7, r6
		sldi	  r9, r6, 8
		or	  r7, r9, r4
		sldi	  r6, r7, 8
		or	  r4, r6, r10
		sldi	  r10, r4, 8
		or	  r9, r10, r8
		sldi	  r8, r9, 8
		or	  r7, r8, r5
		std	  r7, 0x10(r3)
		lwz	  r6, 0x18(r3)
		lbz	  r5, 0x18(r3)
		mr	  r4, r6
		rlwinm	  r10, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r5
		stw	  r7, 0x18(r3)
		lbz	  r6, 0x1C(r3)
		lwz	  r5, 0x1C(r3)
		mr	  r4, r5
		insrwi	  r4, r5, 16,0
		rlwinm	  r10, r5, 24,16,23
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r6
		stw	  r7, 0x1C(r3)
		lwz	  r6, 0x34(r3)
		lbz	  r5, 0x34(r3)
		mr	  r4, r6
		rlwinm	  r10, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r5
		stw	  r7, 0x34(r3)
		lwz	  r6, 0x38(r3)
		lbz	  r5, 0x38(r3)
		mr	  r4, r6
		rlwinm	  r10, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r5
		stw	  r7, 0x38(r3)
		lwz	  r6, 0x3C(r3)
		lbz	  r5, 0x3C(r3)
		mr	  r4, r6
		rlwinm	  r10, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r5
		stw	  r7, 0x3C(r3)
		lhz	  r6, 0x40(r3)
		rotlwi	  r4, r6, 8
		lbz	  r5, 0x40(r3)
		or	  r10, r4, r5
		sth	  r10, 0x40(r3)
		lhz	  r8, 0x42(r3)
		lbz	  r7, 0x42(r3)
		rotlwi	  r6, r8, 8
		or	  r5, r6, r7
		sth	  r5, 0x42(r3)
		lhz	  r10, 0x44(r3)
		lbz	  r9, 0x44(r3)
		rotlwi	  r8, r10, 8
		or	  r7, r8, r9
		sth	  r7, 0x44(r3)
		lbz	  r10, 0x46(r3)
		lhz	  r5, 0x46(r3)
		rotlwi	  r4, r5, 8
		or	  r9, r4, r10
		sth	  r9, 0x46(r3)
		lhz	  r7, 0x48(r3)
		lbz	  r6, 0x48(r3)
		rotlwi	  r5, r7, 8
		or	  r4, r5, r6
		sth	  r4, 0x48(r3)
		lbz	  r8, 0x4A(r3)
		lhz	  r9, 0x4A(r3)
		rotlwi	  r7, r9, 8
		or	  r6, r7, r8
		sth	  r6, 0x4A(r3)
		lhz	  r4, 0x4C(r3)
		rotlwi	  r9, r4, 8
		lbz	  r10, 0x4C(r3)
		or	  r8, r9, r10
		sth	  r8, 0x4C(r3)
		lhz	  r6, 0x4E(r3)
		rotlwi	  r4, r6, 8
		lbz	  r5, 0x4E(r3)
		or	  r10, r4, r5
		sth	  r10, 0x4E(r3)
		lhz	  r8, 0x50(r3)
		lbz	  r6, 0x50(r3)
		rotlwi	  r7, r8, 8
		or	  r5, r7, r6
		sth	  r5, 0x50(r3)
		lhz	  r10, 0x52(r3)
		rotlwi	  r8, r10, 8
		lbz	  r9, 0x52(r3)
		or	  r7, r8, r9
		sth	  r7, 0x52(r3)
		lhz	  r5, 0x54(r3)
		lbz	  r4, 0x54(r3)
		rotlwi	  r10, r5, 8
		or	  r9, r10, r4
		sth	  r9, 0x54(r3)
		lhz	  r7, 0x56(r3)
		lbz	  r6, 0x56(r3)
		rotlwi	  r5, r7, 8
		or	  r4, r5, r6
		sth	  r4, 0x56(r3)
		lhz	  r9, 0x58(r3)
		lbz	  r8, 0x58(r3)
		rotlwi	  r7, r9, 8
		or	  r6, r7, r8
		sth	  r6, 0x58(r3)
		lhz	  r4, 0x5A(r3)
		lbz	  r10, 0x5A(r3)
		rotlwi	  r9, r4, 8
		or	  r8, r9, r10
		sth	  r8, 0x5A(r3)
		lhz	  r6, 0x5C(r3)
		lbz	  r5, 0x5C(r3)
		rotlwi	  r4, r6, 8
		or	  r10, r4, r5
		sth	  r10, 0x5C(r3)
		lhz	  r8, 0x5E(r3)
		lbz	  r6, 0x5E(r3)
		rotlwi	  r7, r8, 8
		or	  r5, r7, r6
		sth	  r5, 0x5E(r3)
		lhz	  r10, 0x60(r3)
		lbz	  r8, 0x60(r3)
		rotlwi	  r9, r10, 8
		or	  r7, r9, r8
		sth	  r7, 0x60(r3)
		lhz	  r4, 0x62(r3)
		lbz	  r5, 0x62(r3)
		rotlwi	  r10, r4, 8
		or	  r9, r10, r5
		sth	  r9, 0x62(r3)
		lbz	  r6, 0x64(r3)
		lhz	  r7, 0x64(r3)
		rotlwi	  r5, r7, 8
		or	  r4, r5, r6
		sth	  r4, 0x64(r3)
		lhz	  r9, 0x66(r3)
		rotlwi	  r8, r9, 8
		lbz	  r7, 0x66(r3)
		or	  r6, r8, r7
		sth	  r6, 0x66(r3)
		lhz	  r4, 0x68(r3)
		rotlwi	  r10, r4, 8
		lbz	  r9, 0x68(r3)
		or	  r8, r10, r9
		sth	  r8, 0x68(r3)
		lbz	  r5, 0x6A(r3)
		lhz	  r6, 0x6A(r3)
		rotlwi	  r4, r6, 8
		or	  r10, r4, r5
		sth	  r10, 0x6A(r3)
		lbz	  r7, 0x6C(r3)
		lhz	  r8, 0x6C(r3)
		rotlwi	  r6, r8, 8
		or	  r5, r6, r7
		sth	  r5, 0x6C(r3)
		lhz	  r10, 0x6E(r3)
		lbz	  r9, 0x6E(r3)
		rotlwi	  r8, r10, 8
		or	  r7, r8, r9
		sth	  r7, 0x6E(r3)
		lhz	  r5, 0x70(r3)
		rotlwi	  r10, r5, 8
		lbz	  r4, 0x70(r3)
		or	  r9, r10, r4
		sth	  r9, 0x70(r3)
		lhz	  r7, 0x72(r3)
		lbz	  r6, 0x72(r3)
		rotlwi	  r5, r7, 8
		or	  r4, r5, r6
		sth	  r4, 0x72(r3)
		lhz	  r9, 0x74(r3)
		rotlwi	  r7, r9, 8
		lbz	  r8, 0x74(r3)
		or	  r6, r7, r8
		sth	  r6, 0x74(r3)
		lhz	  r4, 0x76(r3)
		lbz	  r10, 0x76(r3)
		rotlwi	  r9, r4, 8
		or	  r8, r9, r10
		sth	  r8, 0x76(r3)
		lhz	  r6, 0x78(r3)
		lbz	  r5, 0x78(r3)
		rotlwi	  r4, r6, 8
		or	  r10, r4, r5
		sth	  r10, 0x78(r3)
		lhz	  r8, 0x7A(r3)
		lbz	  r7, 0x7A(r3)
		rotlwi	  r6, r8, 8
		or	  r5, r6, r7
		sth	  r5, 0x7A(r3)
		lhz	  r10, 0x7C(r3)
		lbz	  r9, 0x7C(r3)
		rotlwi	  r8, r10, 8
		or	  r7, r8, r9
		sth	  r7, 0x7C(r3)
		lhz	  r5, 0x7E(r3)
		lbz	  r4, 0x7E(r3)
		rotlwi	  r10, r5, 8
		or	  r9, r10, r4
		li	  r10, 0x64
		sth	  r9, 0x7E(r3)
		mtspr	CTR, r10
		lhz	  r7, 0x80(r3)
		lbz	  r6, 0x80(r3)
		rotlwi	  r5, r7, 8
		or	  r4, r5, r6
		sth	  r4, 0x80(r3)
		lhz	  r9, 0x82(r3)
		lbz	  r8, 0x82(r3)
		rotlwi	  r7, r9, 8
		or	  r6, r7, r8
		sth	  r6, 0x82(r3)
		lhz	  r4, 0x84(r3)
		lbz	  r9, 0x84(r3)
		rotlwi	  r8, r4, 8
		or	  r7, r8, r9
		sth	  r7, 0x84(r3)
		lhz	  r5, 0x86(r3)
		rotlwi	  r10, r5, 8
		lbz	  r4, 0x86(r3)
		or	  r9, r10, r4
		sth	  r9, 0x86(r3)
		lhz	  r7, 0x88(r3)
		rotlwi	  r5, r7, 8
		lbz	  r6, 0x88(r3)
		or	  r4, r5, r6
		sth	  r4, 0x88(r3)
		lhz	  r9, 0x8A(r3)
		rotlwi	  r7, r9, 8
		lbz	  r8, 0x8A(r3)
		or	  r6, r7, r8
		sth	  r6, 0x8A(r3)
		lhz	  r4, 0x8C(r3)
		rotlwi	  r9, r4, 8
		lbz	  r10, 0x8C(r3)
		or	  r8, r9, r10
		sth	  r8, 0x8C(r3)
		lwz	  r6, 0x94(r3)
		lbz	  r5, 0x94(r3)
		mr	  r4, r6
		rlwinm	  r10, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r5
		stw	  r7, 0x94(r3)
		lwz	  r6, 0x98(r3)
		lbz	  r5, 0x98(r3)
		mr	  r4, r6
		rlwinm	  r10, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r5
		stw	  r7, 0x98(r3)
		lwz	  r6, 0x9C(r3)
		lbz	  r5, 0x9C(r3)
		mr	  r4, r6
		rlwinm	  r10, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r5
		stw	  r7, 0x9C(r3)
		lwzu	  r10, 0x100(r11)
		mr	  r6, r10
		rlwinm	  r5, r10, 24,16,23
		insrwi	  r6, r10, 16,0
		lwz	  r4, 4(r11)
		lwz	  r3, 8(r11)
		extlwi	  r10, r6, 16,8
		lwz	  r9, 0xC(r11)
		mr	  r8, r4
		mr	  r7, r3
		lbz	  r6, 0(r11)
		mr	  r31, r9
		lbz	  r30, 4(r11)
		insrwi	  r8, r4, 16,0
		lbz	  r28, 8(r11)
		insrwi	  r7, r3, 16,0
		lbz	  r27, 0xC(r11)
		insrwi	  r31, r9, 16,0
		rlwinm	  r4, r4, 24,16,23
		extlwi	  r8, r8, 16,8
		or	  r5, r10, r5
		rlwinm	  r3, r3, 24,16,23
		extlwi	  r7, r7, 16,8
		rlwinm	  r9, r9, 24,16,23
		extlwi	  r10, r31, 16,8
		or	  r8, r8, r4
		or	  r7, r7, r3
		or	  r6, r5, r6
		or	  r5, r10, r9
		or	  r4, r8, r30
		stw	  r6, 0(r11)
		or	  r3, r7, r28
		or	  r10, r5, r27
		stw	  r4, 4(r11)
		stw	  r3, 8(r11)
		stw	  r10, 0xC(r11)
		lwzu	  r10, 0x10(r11)
		mr	  r9, r10
		rlwinm	  r8, r10, 24,16,23
		insrwi	  r9, r10, 16,0
		lbz	  r7, 0(r11)
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r8
		or	  r4, r5, r7
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r8, 0(r11)
		rlwinm	  r9, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		ld	  r29, 0x50(r1)
		stw	  r5, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		rlwinm	  r3, r10, 24,16,23
		insrwi	  r4, r10, 16,0
		lbz	  r10, 0(r11)
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r3
		or	  r7, r8, r10
		stw	  r7, 0(r11)
		lhzu	  r6, 4(r11)
		rotlwi	  r5, r6, 8
		lbz	  r4, 0(r11)
		or	  r3, r5, r4
		sth	  r3, 0(r11)
		lhzu	  r9, 2(r11)
		rotlwi	  r8, r9, 8
		lbz	  r7, 0(r11)
		or	  r6, r8, r7
		sth	  r6, 0(r11)
		addi	  r11, r11, 0x2002

loc_82569C80:				// CODE XREF: sub_82568170+1BA0j
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_82569C80
		li	  r10, 0x30
		mtspr	CTR, r10

loc_82569D1C:				// CODE XREF: sub_82568170+1C88j
		lwz	  r10, 0(r11)
		lwz	  r9, 4(r11)
		lwz	  r8, 8(r11)
		mr	  r7, r10
		lwz	  r6, 0xC(r11)
		mr	  r5, r9
		lwz	  r4, 0x10(r11)
		mr	  r3, r8
		lwz	  r31, 0x14(r11)
		insrwi	  r7, r10, 16,0
		insrwi	  r5, r9, 16,0
		lbz	  r28, 0(r11)
		mr	  r30, r6
		lbz	  r27, 4(r11)
		insrwi	  r3, r8, 16,0
		lbz	  r25, 8(r11)
		mr	  r26, r4
		lbz	  r24, 0xC(r11)
		extlwi	  r7, r7, 16,8
		lbz	  r22, 0x10(r11)
		rlwinm	  r10, r10, 24,16,23
		lbz	  r21, 0x14(r11)
		mr	  r23, r31
		insrwi	  r30, r6, 16,0
		rlwinm	  r9, r9, 24,16,23
		extlwi	  r5, r5, 16,8
		insrwi	  r26, r4, 16,0
		rlwinm	  r8, r8, 24,16,23
		extlwi	  r3, r3, 16,8
		or	  r7, r7, r10
		insrwi	  r23, r31, 16,0
		or	  r5, r5, r9
		extlwi	  r10, r30, 16,8
		rlwinm	  r6, r6, 24,16,23
		or	  r3, r3, r8
		extlwi	  r9, r26, 16,8
		rlwinm	  r4, r4, 24,16,23
		extlwi	  r8, r23, 16,8
		rlwinm	  r31, r31, 24,16,23
		or	  r7, r7, r28
		or	  r6, r10, r6
		or	  r4, r9, r4
		stw	  r7, 0(r11)
		or	  r5, r5, r27
		or	  r10, r8, r31
		or	  r3, r3, r25
		stw	  r5, 4(r11)
		or	  r9, r6, r24
		or	  r8, r4, r22
		stw	  r3, 8(r11)
		or	  r7, r10, r21
		stw	  r9, 0xC(r11)
		stw	  r8, 0x10(r11)
		stw	  r7, 0x14(r11)
		addi	  r11, r11, 0x18
		bdnz	  loc_82569D1C
		li	  r10, 0x30
		mtspr	CTR, r10

loc_82569E04:				// CODE XREF: sub_82568170+1D24j
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_82569E04
		li	  r10, 0x30
		mtspr	CTR, r10

loc_82569EA0:				// CODE XREF: sub_82568170+1DC0j
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_82569EA0
		li	  r10, 0x30
		mtspr	CTR, r10

loc_82569F3C:				// CODE XREF: sub_82568170+1E5Cj
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_82569F3C
		li	  r10, 0x30
		mtspr	CTR, r10

loc_82569FD8:				// CODE XREF: sub_82568170+1EF8j
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_82569FD8
		li	  r10, 0x30
		mtspr	CTR, r10

loc_8256A074:				// CODE XREF: sub_82568170+1F94j
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_8256A074
		li	  r10, 0x30
		mtspr	CTR, r10

loc_8256A110:				// CODE XREF: sub_82568170+2030j
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_8256A110
		li	  r10, 0x30
		mtspr	CTR, r10

loc_8256A1AC:				// CODE XREF: sub_82568170+20CCj
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_8256A1AC
		li	  r10, 0x30
		mtspr	CTR, r10

loc_8256A248:				// CODE XREF: sub_82568170+21B4j
		lwz	  r10, 0(r11)
		lwz	  r9, 4(r11)
		lwz	  r8, 8(r11)
		mr	  r7, r10
		lwz	  r6, 0xC(r11)
		mr	  r5, r9
		lwz	  r4, 0x10(r11)
		mr	  r3, r8
		lwz	  r31, 0x14(r11)
		insrwi	  r7, r10, 16,0
		insrwi	  r5, r9, 16,0
		lbz	  r28, 0(r11)
		mr	  r30, r6
		lbz	  r27, 4(r11)
		insrwi	  r3, r8, 16,0
		lbz	  r25, 8(r11)
		mr	  r26, r4
		lbz	  r24, 0xC(r11)
		extlwi	  r7, r7, 16,8
		lbz	  r22, 0x10(r11)
		rlwinm	  r10, r10, 24,16,23
		lbz	  r21, 0x14(r11)
		mr	  r23, r31
		insrwi	  r30, r6, 16,0
		rlwinm	  r9, r9, 24,16,23
		extlwi	  r5, r5, 16,8
		insrwi	  r26, r4, 16,0
		rlwinm	  r8, r8, 24,16,23
		extlwi	  r3, r3, 16,8
		or	  r7, r7, r10
		insrwi	  r23, r31, 16,0
		or	  r5, r5, r9
		extlwi	  r10, r30, 16,8
		rlwinm	  r6, r6, 24,16,23
		or	  r3, r3, r8
		extlwi	  r9, r26, 16,8
		rlwinm	  r4, r4, 24,16,23
		extlwi	  r8, r23, 16,8
		rlwinm	  r31, r31, 24,16,23
		or	  r7, r7, r28
		or	  r6, r10, r6
		or	  r4, r9, r4
		stw	  r7, 0(r11)
		or	  r5, r5, r27
		or	  r10, r8, r31
		or	  r3, r3, r25
		stw	  r5, 4(r11)
		or	  r9, r6, r24
		or	  r8, r4, r22
		stw	  r3, 8(r11)
		or	  r7, r10, r21
		stw	  r9, 0xC(r11)
		stw	  r8, 0x10(r11)
		stw	  r7, 0x14(r11)
		addi	  r11, r11, 0x18
		bdnz	  loc_8256A248
		li	  r10, 0x30
		mtspr	CTR, r10

loc_8256A330:				// CODE XREF: sub_82568170+2250j
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_8256A330
		li	  r10, 0x30
		mtspr	CTR, r10

loc_8256A3CC:				// CODE XREF: sub_82568170+22ECj
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_8256A3CC
		li	  r10, 0x30
		mtspr	CTR, r10

loc_8256A468:				// CODE XREF: sub_82568170+2388j
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_8256A468
		li	  r10, 0x30
		mtspr	CTR, r10

loc_8256A504:				// CODE XREF: sub_82568170+2424j
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_8256A504
		li	  r10, 0x30
		mtspr	CTR, r10

loc_8256A5A0:				// CODE XREF: sub_82568170+24C0j
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_8256A5A0
		li	  r10, 0x30
		mtspr	CTR, r10

loc_8256A63C:				// CODE XREF: sub_82568170+255Cj
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_8256A63C
		li	  r10, 0x30
		mtspr	CTR, r10

loc_8256A6D8:				// CODE XREF: sub_82568170+25F8j
		lhz	  r10, 0(r11)
		lhz	  r9, 2(r11)
		lhz	  r8, 4(r11)
		rotlwi	  r7, r10, 8
		lbz	  r6, 0(r11)
		rotlwi	  r5, r9, 8
		lbz	  r10, 2(r11)
		rotlwi	  r3, r8, 8
		lhz	  r4, 6(r11)
		or	  r9, r7, r6
		lhz	  r8, 8(r11)
		or	  r5, r5, r10
		lbz	  r6, 4(r11)
		rotlwi	  r7, r4, 8
		rotlwi	  r10, r8, 8
		lhz	  r4, 0xA(r11)
		lbz	  r8, 6(r11)
		or	  r6, r3, r6
		lbz	  r3, 8(r11)
		rotlwi	  r4, r4, 8
		lbz	  r31, 0xA(r11)
		or	  r8, r7, r8
		mr	  r7, r5
		sth	  r9, 0(r11)
		or	  r5, r10, r3
		clrlwi	  r3, r6, 16
		sth	  r7, 2(r11)
		or	  r10, r4, r31
		clrlwi	  r9, r8, 16
		sth	  r3, 4(r11)
		clrlwi	  r8, r5, 16
		clrlwi	  r7, r10, 16
		sth	  r9, 6(r11)
		sth	  r8, 8(r11)
		sth	  r7, 0xA(r11)
		addi	  r11, r11, 0xC
		bdnz	  loc_8256A6D8
		lwzu	  r10, 0x10(r11)
		li	  r9, 0x14
		mr	  r8, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		lbz	  r6, 0(r11)
		mtspr	CTR, r9
		extlwi	  r5, r8, 16,8
		or	  r4, r5, r7
		or	  r3, r4, r6
		stw	  r3, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		rlwinm	  r8, r10, 24,16,23
		insrwi	  r9, r10, 16,0
		lbz	  r7, 0(r11)
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r8
		or	  r4, r5, r7
		stw	  r4, 0(r11)
		lwzu	  r10, 0x5004(r11)
		mr	  r3, r10
		rlwinm	  r9, r10, 24,16,23
		insrwi	  r3, r10, 16,0
		lbz	  r8, 0(r11)
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r4, r10
		rlwinm	  r3, r10, 24,16,23
		insrwi	  r4, r10, 16,0
		lbz	  r10, 0(r11)
		extlwi	  r9, r4, 16,8
		or	  r8, r9, r3
		or	  r7, r8, r10
		stw	  r7, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r6, r10
		rlwinm	  r5, r10, 24,16,23
		insrwi	  r6, r10, 16,0
		lbz	  r4, 0(r11)
		extlwi	  r3, r6, 16,8
		or	  r10, r3, r5
		or	  r9, r10, r4
		stw	  r9, 0(r11)
		lwzu	  r10, 0x1C(r11)
		mr	  r8, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		lbz	  r6, 0(r11)
		extlwi	  r5, r8, 16,8
		or	  r4, r5, r7
		or	  r3, r4, r6
		stw	  r3, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		rlwinm	  r8, r10, 24,16,23
		insrwi	  r9, r10, 16,0
		lbz	  r7, 0(r11)
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r8
		or	  r4, r5, r7
		stw	  r4, 0(r11)
		lwzu	  r10, 4(r11)
		mr	  r3, r10
		insrwi	  r3, r10, 16,0
		lbz	  r8, 0(r11)
		rlwinm	  r9, r10, 24,16,23
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0(r11)
		addi	  r11, r11, 4

loc_8256A898:				// CODE XREF: sub_82568170+2750j
		lwz	  r10, 0(r11)
		lbz	  r9, 0(r11)
		mr	  r8, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r9
		stw	  r4, 0(r11)
		addi	  r11, r11, 4
		bdnz	  loc_8256A898
		lwz	  r10, 0(r11)
		lbz	  r9, 0(r11)
		mr	  r8, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r9
		stw	  r4, 0(r11)
		lwz	  r3, 4(r11)
		lbz	  r10, 4(r11)
		mr	  r9, r3
		rlwinm	  r8, r3, 24,16,23
		insrwi	  r9, r3, 16,0
		extlwi	  r7, r9, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r10
		stw	  r5, 4(r11)
		lwz	  r4, 8(r11)
		mr	  r10, r4
		insrwi	  r10, r4, 16,0
		lbz	  r3, 8(r11)
		rlwinm	  r9, r4, 24,16,23
		extlwi	  r8, r10, 16,8
		or	  r7, r8, r9
		or	  r6, r7, r3
		stw	  r6, 8(r11)
		lwz	  r5, 0xC(r11)
		lbz	  r4, 0xC(r11)
		mr	  r3, r5
		rlwinm	  r10, r5, 24,16,23
		insrwi	  r3, r5, 16,0
		extlwi	  r9, r3, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r4
		stw	  r7, 0xC(r11)
		lwz	  r6, 0x10(r11)
		lbz	  r5, 0x10(r11)
		mr	  r4, r6
		rlwinm	  r3, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r10, r4, 16,8
		or	  r9, r10, r3
		or	  r8, r9, r5
		stw	  r8, 0x10(r11)
		lwz	  r7, 0x14(r11)
		lbz	  r6, 0x14(r11)
		mr	  r5, r7
		rlwinm	  r4, r7, 24,16,23
		insrwi	  r5, r7, 16,0
		extlwi	  r3, r5, 16,8
		or	  r10, r3, r4
		or	  r9, r10, r6
		stw	  r9, 0x14(r11)
		lwz	  r8, 0x18(r11)
		lbz	  r7, 0x18(r11)
		mr	  r6, r8
		rlwinm	  r5, r8, 24,16,23
		insrwi	  r6, r8, 16,0
		extlwi	  r4, r6, 16,8
		or	  r3, r4, r5
		or	  r10, r3, r7
		stw	  r10, 0x18(r11)
		lwz	  r9, 0x1C(r11)
		lbz	  r8, 0x1C(r11)
		mr	  r7, r9
		rlwinm	  r6, r9, 24,16,23
		insrwi	  r7, r9, 16,0
		extlwi	  r5, r7, 16,8
		or	  r4, r5, r6
		or	  r3, r4, r8
		stw	  r3, 0x1C(r11)
		lwz	  r10, 0x20(r11)
		lbz	  r9, 0x20(r11)
		mr	  r8, r10
		rlwinm	  r7, r10, 24,16,23
		insrwi	  r8, r10, 16,0
		extlwi	  r6, r8, 16,8
		li	  r8, 6
		or	  r5, r6, r7
		or	  r4, r5, r9
		stw	  r4, 0x20(r11)
		lwz	  r3, 0x24(r11)
		lbz	  r10, 0x24(r11)
		mr	  r9, r3
		rlwinm	  r7, r3, 24,16,23
		insrwi	  r9, r3, 16,0
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r10
		stw	  r4, 0x24(r11)
		lwz	  r3, 0x28(r11)
		lbz	  r10, 0x28(r11)
		mr	  r9, r3
		rlwinm	  r7, r3, 24,16,23
		insrwi	  r9, r3, 16,0
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r10
		stw	  r4, 0x28(r11)
		lwz	  r3, 0x2C(r11)
		lbz	  r10, 0x2C(r11)
		mr	  r9, r3
		rlwinm	  r7, r3, 24,16,23
		insrwi	  r9, r3, 16,0
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r10
		stw	  r4, 0x2C(r11)
		lwz	  r3, 0x30(r11)
		lbz	  r10, 0x30(r11)
		mr	  r9, r3
		rlwinm	  r7, r3, 24,16,23
		insrwi	  r9, r3, 16,0
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r10
		stw	  r4, 0x30(r11)
		lhz	  r3, 0x34(r11)
		lbz	  r10, 0x34(r11)
		rotlwi	  r9, r3, 8
		or	  r7, r9, r10
		sth	  r7, 0x34(r11)
		lhz	  r5, 0x36(r11)
		lbz	  r4, 0x36(r11)
		rotlwi	  r3, r5, 8
		or	  r10, r3, r4
		sth	  r10, 0x36(r11)
		lhz	  r7, 0x38(r11)
		lbz	  r6, 0x38(r11)
		rotlwi	  r5, r7, 8
		or	  r4, r5, r6
		sth	  r4, 0x38(r11)
		lhz	  r10, 0x3A(r11)
		lbz	  r9, 0x3A(r11)
		rotlwi	  r7, r10, 8
		or	  r6, r7, r9
		sth	  r6, 0x3A(r11)
		lwzu	  r10, 0x80(r11)
		mr	  r4, r10
		rlwinm	  r3, r10, 24,16,23
		insrwi	  r4, r10, 16,0
		lbz	  r10, 0(r11)
		extlwi	  r9, r4, 16,8
		or	  r7, r9, r3
		or	  r6, r7, r10
		stw	  r6, 0(r11)
		lhzu	  r5, 4(r11)
		rotlwi	  r4, r5, 8
		lbz	  r3, 0(r11)
		or	  r10, r4, r3
		sth	  r10, 0(r11)
		lhzu	  r7, 2(r11)
		rotlwi	  r6, r7, 8
		lbz	  r5, 0(r11)
		addi	  r7, r11, 2
		or	  r4, r6, r5
		mr	  r10, r7
		sth	  r4, 0(r11)

loc_8256AB40:				// CODE XREF: sub_82568170+2B04j
		lhz	  r6, 0(r10)
		li	  r9, 5
		lbz	  r5, 0(r10)
		addi	  r11, r10, 0x50
		rotlwi	  r4, r6, 8
		or	  r3, r4, r5
		mtspr	CTR, r9
		sth	  r3, 0(r10)

loc_8256AB60:				// CODE XREF: sub_82568170+2AF8j
		lhz	  r6, -0x4E(r11)
		lbz	  r9, -0x4E(r11)
		insrwi	  r9, r6, 16,8
		sth	  r9, -0x4E(r11)
		lhz	  r3, 2(r11)
		lbz	  r4, 2(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 2(r11)
		lhz	  r5, -0x4C(r11)
		lbz	  r6, -0x4C(r11)
		insrwi	  r6, r5, 16,8
		sth	  r6, -0x4C(r11)
		lhz	  r3, 4(r11)
		lbz	  r9, 4(r11)
		insrwi	  r9, r3, 16,8
		sth	  r9, 4(r11)
		lhz	  r4, -0x4A(r11)
		lbz	  r5, -0x4A(r11)
		insrwi	  r5, r4, 16,8
		sth	  r5, -0x4A(r11)
		lhz	  r6, 6(r11)
		lbz	  r9, 6(r11)
		insrwi	  r9, r6, 16,8
		sth	  r9, 6(r11)
		lhz	  r3, -0x48(r11)
		lbz	  r4, -0x48(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, -0x48(r11)
		lhz	  r5, 8(r11)
		lbz	  r6, 8(r11)
		insrwi	  r6, r5, 16,8
		sth	  r6, 8(r11)
		lhz	  r9, -0x46(r11)
		lbz	  r3, -0x46(r11)
		insrwi	  r3, r9, 16,8
		sth	  r3, -0x46(r11)
		lhz	  r5, 0xA(r11)
		lbz	  r4, 0xA(r11)
		insrwi	  r4, r5, 16,8
		sth	  r4, 0xA(r11)
		lhz	  r6, -0x44(r11)
		lbz	  r9, -0x44(r11)
		insrwi	  r9, r6, 16,8
		sth	  r9, -0x44(r11)
		lhz	  r3, 0xC(r11)
		lbz	  r4, 0xC(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0xC(r11)
		lhz	  r5, -0x42(r11)
		lbz	  r6, -0x42(r11)
		insrwi	  r6, r5, 16,8
		sth	  r6, -0x42(r11)
		lbz	  r3, 0xE(r11)
		lhz	  r9, 0xE(r11)
		insrwi	  r3, r9, 16,8
		sth	  r3, 0xE(r11)
		lbz	  r5, -0x40(r11)
		lhz	  r4, -0x40(r11)
		insrwi	  r5, r4, 16,8
		clrlwi	  r3, r5, 16
		sth	  r3, -0x40(r11)
		lbz	  r9, 0x10(r11)
		lhz	  r6, 0x10(r11)
		insrwi	  r9, r6, 16,8
		clrlwi	  r5, r9, 16
		sthu	  r5, 0x10(r11)
		bdnz	  loc_8256AB60
		addic.	  r8, r8, -1
		addi	  r10, r10, 0xA2
		bne	  loc_8256AB40
		li	  r11, 0x20
		addi	  r10, r7, 0x590
		mtspr	CTR, r11

loc_8256AC84:				// CODE XREF: sub_82568170+2BA8j
		lwz	  r11, 0(r10)
		lwz	  r9, 4(r10)
		lwz	  r8, 8(r10)
		mr	  r7, r11
		lwz	  r6, 0xC(r10)
		mr	  r5, r9
		insrwi	  r7, r11, 16,0
		lbz	  r3, 0(r10)
		mr	  r4, r8
		lbz	  r31, 4(r10)
		mr	  r30, r6
		lbz	  r28, 8(r10)
		insrwi	  r5, r9, 16,0
		lbz	  r27, 0xC(r10)
		insrwi	  r4, r8, 16,0
		rlwinm	  r11, r11, 24,16,23
		extlwi	  r7, r7, 16,8
		insrwi	  r30, r6, 16,0
		rlwinm	  r9, r9, 24,16,23
		extlwi	  r5, r5, 16,8
		or	  r7, r7, r11
		rlwinm	  r8, r8, 24,16,23
		extlwi	  r4, r4, 16,8
		extlwi	  r11, r30, 16,8
		rlwinm	  r6, r6, 24,16,23
		or	  r5, r5, r9
		or	  r4, r4, r8
		or	  r3, r7, r3
		or	  r11, r11, r6
		or	  r9, r5, r31
		stw	  r3, 0(r10)
		or	  r8, r4, r28
		or	  r7, r11, r27
		stw	  r9, 4(r10)
		stw	  r8, 8(r10)
		stw	  r7, 0xC(r10)
		addi	  r10, r10, 0x10
		bdnz	  loc_8256AC84
		li	  r11, 0
		cmpwi	  cr6, r29, 1
		bne	  cr6, loc_8256AD2C
		lwz	  r11, 0(r10)

loc_8256AD2C:				// CODE XREF: sub_82568170+2BB4j
		lwz	  r9, 0(r10)
		cmpwi	  cr6, r29, 0
		lbz	  r8, 0(r10)
		mr	  r7, r9
		rlwinm	  r6, r9, 24,16,23
		insrwi	  r7, r9, 16,0
		extlwi	  r5, r7, 16,8
		or	  r4, r5, r6
		or	  r9, r4, r8
		stw	  r9, 0(r10)
		bne	  cr6, loc_8256AD5C
		mr	  r11, r9

loc_8256AD5C:				// CODE XREF: sub_82568170+2BE4j
		addi	  r9, r10, 4
		cmplwi	  cr6, r11, 0
		beq	  cr6, loc_8256AE60
		mtspr	CTR, r11
		addi	  r11, r9, -4

loc_8256AD70:				// CODE XREF: sub_82568170+2CECj
		lwz	  r9, 4(r11)
		lbz	  r5, 4(r11)
		mr	  r7, r9
		rlwinm	  r6, r9, 24,16,23
		insrwi	  r7, r9, 16,0
		extlwi	  r4, r7, 16,8
		or	  r3, r4, r6
		or	  r9, r3, r5
		stw	  r9, 4(r11)
		lwz	  r8, 8(r11)
		lbz	  r4, 8(r11)
		mr	  r6, r8
		rlwinm	  r5, r8, 24,16,23
		insrwi	  r6, r8, 16,0
		extlwi	  r3, r6, 16,8
		or	  r9, r3, r5
		or	  r8, r9, r4
		stw	  r8, 8(r11)
		lwz	  r7, 0xC(r11)
		lbz	  r3, 0xC(r11)
		mr	  r5, r7
		rlwinm	  r4, r7, 24,16,23
		insrwi	  r5, r7, 16,0
		extlwi	  r9, r5, 16,8
		or	  r8, r9, r4
		or	  r7, r8, r3
		stw	  r7, 0xC(r11)
		lwz	  r6, 0x10(r11)
		lbz	  r9, 0x10(r11)
		mr	  r4, r6
		rlwinm	  r3, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r8, r4, 16,8
		or	  r7, r8, r3
		or	  r6, r7, r9
		stw	  r6, 0x10(r11)
		lwz	  r5, 0x14(r11)
		lbz	  r8, 0x14(r11)
		mr	  r3, r5
		rlwinm	  r9, r5, 24,16,23
		insrwi	  r3, r5, 16,0
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0x14(r11)
		lhz	  r3, 0x18(r11)
		lbz	  r4, 0x18(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x18(r11)
		lwz	  r8, 0x1C(r11)
		lbz	  r7, 0x1C(r11)
		mr	  r6, r8
		rlwinm	  r5, r8, 24,16,23
		insrwi	  r6, r8, 16,0
		mr	  r4, r7
		extlwi	  r3, r6, 16,8
		or	  r9, r3, r5
		or	  r8, r9, r7
		stwu	  r8, 0x1C(r11)
		bdnz	  loc_8256AD70

loc_8256AE60:				// CODE XREF: sub_82568170+2BF4j
		addi	  r10, r10, 0x2580
		li	  r11, 0
		cmpwi	  cr6, r29, 1
		bne	  cr6, loc_8256AE74
		lwz	  r11, 0(r10)

loc_8256AE74:				// CODE XREF: sub_82568170+2CFCj
		lwz	  r9, 0(r10)
		cmpwi	  cr6, r29, 0
		lbz	  r8, 0(r10)
		mr	  r7, r9
		rlwinm	  r6, r9, 24,16,23
		insrwi	  r7, r9, 16,0
		extlwi	  r5, r7, 16,8
		or	  r4, r5, r6
		or	  r9, r4, r8
		stw	  r9, 0(r10)
		bne	  cr6, loc_8256AEA4
		mr	  r11, r9

loc_8256AEA4:				// CODE XREF: sub_82568170+2D2Cj
		addi	  r9, r10, 4
		cmplwi	  cr6, r11, 0
		beq	  cr6, loc_8256AF98
		mtspr	CTR, r11
		addi	  r11, r9, -4

loc_8256AEB8:				// CODE XREF: sub_82568170+2E24j
		lwz	  r9, 4(r11)
		lbz	  r5, 4(r11)
		mr	  r7, r9
		rlwinm	  r6, r9, 24,16,23
		insrwi	  r7, r9, 16,0
		extlwi	  r4, r7, 16,8
		or	  r3, r4, r6
		or	  r9, r3, r5
		stw	  r9, 4(r11)
		lwz	  r8, 8(r11)
		lbz	  r4, 8(r11)
		mr	  r6, r8
		rlwinm	  r5, r8, 24,16,23
		insrwi	  r6, r8, 16,0
		extlwi	  r3, r6, 16,8
		or	  r9, r3, r5
		or	  r8, r9, r4
		stw	  r8, 8(r11)
		lwz	  r7, 0xC(r11)
		lbz	  r3, 0xC(r11)
		mr	  r5, r7
		rlwinm	  r4, r7, 24,16,23
		insrwi	  r5, r7, 16,0
		extlwi	  r9, r5, 16,8
		or	  r8, r9, r4
		or	  r7, r8, r3
		stw	  r7, 0xC(r11)
		lwz	  r6, 0x10(r11)
		lbz	  r9, 0x10(r11)
		mr	  r4, r6
		rlwinm	  r3, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r8, r4, 16,8
		or	  r7, r8, r3
		or	  r6, r7, r9
		stw	  r6, 0x10(r11)
		lwz	  r5, 0x14(r11)
		lbz	  r8, 0x14(r11)
		mr	  r3, r5
		rlwinm	  r9, r5, 24,16,23
		insrwi	  r3, r5, 16,0
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0x14(r11)
		lwz	  r4, 0x18(r11)
		lbz	  r3, 0x18(r11)
		mr	  r9, r4
		rlwinm	  r8, r4, 24,16,23
		insrwi	  r9, r4, 16,0
		mr	  r7, r3
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r8
		or	  r4, r5, r3
		stwu	  r4, 0x18(r11)
		bdnz	  loc_8256AEB8

loc_8256AF98:				// CODE XREF: sub_82568170+2D3Cj
		addi	  r31, r10, 0x2F80
		li	  r30, 0
		cmpwi	  cr6, r29, 1
		bne	  cr6, loc_8256AFAC
		lwz	  r30, 0(r31)

loc_8256AFAC:				// CODE XREF: sub_82568170+2E34j
		lwz	  r11, 0(r31)
		cmpwi	  cr6, r29, 0
		lbz	  r10, 0(r31)
		mr	  r9, r11
		rlwinm	  r8, r11, 24,16,23
		insrwi	  r9, r11, 16,0
		extlwi	  r7, r9, 16,8
		or	  r6, r7, r8
		or	  r11, r6, r10
		stw	  r11, 0(r31)
		bne	  cr6, loc_8256AFDC
		mr	  r30, r11

loc_8256AFDC:				// CODE XREF: sub_82568170+2E64j
		lwz	  r11, 4(r31)
		addi	  r3, r31, 0x10
		lbz	  r10, 4(r31)
		cmplwi	  cr6, r30, 0
		mr	  r9, r11
		rlwinm	  r8, r11, 24,16,23
		insrwi	  r9, r11, 16,0
		extlwi	  r7, r9, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r10
		stw	  r5, 4(r31)
		lwz	  r4, 8(r31)
		lbz	  r11, 8(r31)
		mr	  r10, r4
		rlwinm	  r9, r4, 24,16,23
		insrwi	  r10, r4, 16,0
		extlwi	  r8, r10, 16,8
		or	  r7, r8, r9
		or	  r6, r7, r11
		stw	  r6, 8(r31)
		lwz	  r5, 0xC(r31)
		lbz	  r4, 0xC(r31)
		mr	  r11, r5
		rlwinm	  r10, r5, 24,16,23
		insrwi	  r11, r5, 16,0
		extlwi	  r9, r11, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r4
		stw	  r7, 0xC(r31)
		beq	  cr6, loc_8256B064

loc_8256B054:				// CODE XREF: sub_82568170+2EF0j
		bl	  sub_82567D18
		addic.	  r30, r30, -1
		addi	  r3, r3, 0xA0
		bne	  loc_8256B054

loc_8256B064:				// CODE XREF: sub_82568170+2EE0j
		addi	  r31, r31, 0x35C
		li	  r30, 0
		cmpwi	  cr6, r29, 1
		bne	  cr6, loc_8256B078
		lwz	  r30, 0(r31)

loc_8256B078:				// CODE XREF: sub_82568170+2F00j
		lwz	  r11, 0(r31)
		cmpwi	  cr6, r29, 0
		lbz	  r10, 0(r31)
		mr	  r9, r11
		rlwinm	  r8, r11, 24,16,23
		insrwi	  r9, r11, 16,0
		extlwi	  r7, r9, 16,8
		or	  r6, r7, r8
		or	  r11, r6, r10
		stw	  r11, 0(r31)
		bne	  cr6, loc_8256B0A8
		mr	  r30, r11

loc_8256B0A8:				// CODE XREF: sub_82568170+2F30j
		lwz	  r11, 4(r31)
		addi	  r3, r31, 0x10
		lbz	  r10, 4(r31)
		cmplwi	  cr6, r30, 0
		mr	  r9, r11
		rlwinm	  r8, r11, 24,16,23
		insrwi	  r9, r11, 16,0
		extlwi	  r7, r9, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r10
		stw	  r5, 4(r31)
		lwz	  r4, 8(r31)
		lbz	  r11, 8(r31)
		mr	  r10, r4
		rlwinm	  r9, r4, 24,16,23
		insrwi	  r10, r4, 16,0
		extlwi	  r8, r10, 16,8
		or	  r7, r8, r9
		or	  r6, r7, r11
		stw	  r6, 8(r31)
		lwz	  r5, 0xC(r31)
		lbz	  r4, 0xC(r31)
		mr	  r11, r5
		rlwinm	  r10, r5, 24,16,23
		insrwi	  r11, r5, 16,0
		extlwi	  r9, r11, 16,8
		or	  r8, r9, r10
		or	  r7, r8, r4
		stw	  r7, 0xC(r31)
		beq	  cr6, loc_8256B130

loc_8256B120:				// CODE XREF: sub_82568170+2FBCj
		bl	  sub_82567D18
		addic.	  r30, r30, -1
		addi	  r3, r3, 0xA0
		bne	  loc_8256B120

loc_8256B130:				// CODE XREF: sub_82568170+2FACj
		lwzu	  r11, 0x2198(r31)
		mr	  r9, r11
		rlwinm	  r8, r11, 24,16,23
		insrwi	  r9, r11, 16,0
		lbz	  r7, 0(r31)
		addi	  r10, r31, 0x1C
		extlwi	  r6, r9, 16,8
		li	  r10, 0
		or	  r5, r6, r8
		or	  r4, r5, r7
		stw	  r4, 0(r31)
		lwz	  r3, 4(r31)
		lbz	  r11, 4(r31)
		mr	  r9, r3
		rlwinm	  r8, r3, 24,16,23
		insrwi	  r9, r3, 16,0
		extlwi	  r7, r9, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r11
		stw	  r5, 4(r31)
		lwz	  r4, 8(r31)
		lbz	  r3, 8(r31)
		mr	  r11, r4
		rlwinm	  r9, r4, 24,16,23
		insrwi	  r11, r4, 16,0
		extlwi	  r8, r11, 16,8
		or	  r7, r8, r9
		or	  r6, r7, r3
		stw	  r6, 8(r31)
		lwz	  r5, 0xC(r31)
		lbz	  r4, 0xC(r31)
		mr	  r3, r5
		rlwinm	  r11, r5, 24,16,23
		insrwi	  r3, r5, 16,0
		extlwi	  r9, r3, 16,8
		or	  r8, r9, r11
		or	  r7, r8, r4
		stw	  r7, 0xC(r31)
		lwz	  r6, 0x10(r31)
		lbz	  r5, 0x10(r31)
		mr	  r4, r6
		rlwinm	  r3, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r11, r4, 16,8
		or	  r9, r11, r3
		or	  r8, r9, r5
		stw	  r8, 0x10(r31)
		lwz	  r7, 0x18(r31)
		lbz	  r6, 0x18(r31)
		mr	  r5, r7
		rlwinm	  r4, r7, 24,16,23
		insrwi	  r5, r7, 16,0
		extlwi	  r3, r5, 16,8
		or	  r11, r3, r4
		or	  r9, r11, r6
		stw	  r9, 0x18(r31)
		lwz	  r8, 0x6C(r31)
		lbz	  r7, 0x6C(r31)
		mr	  r6, r8
		rlwinm	  r5, r8, 24,16,23
		insrwi	  r6, r8, 16,0
		extlwi	  r4, r6, 16,8
		or	  r3, r4, r5
		or	  r11, r3, r7
		stw	  r11, 0x6C(r31)
		lwz	  r9, 0x70(r31)
		lbz	  r8, 0x70(r31)
		mr	  r7, r9
		rlwinm	  r6, r9, 24,16,23
		insrwi	  r7, r9, 16,0
		extlwi	  r5, r7, 16,8
		or	  r4, r5, r6
		or	  r3, r4, r8
		stw	  r3, 0x70(r31)
		lwz	  r11, 0x74(r31)
		lbz	  r9, 0x74(r31)
		mr	  r8, r11
		rlwinm	  r7, r11, 24,16,23
		insrwi	  r8, r11, 16,0
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r9
		cmpwi	  cr6, r29, 1
		stw	  r4, 0x74(r31)
		lwz	  r3, 0x78(r31)
		lbz	  r11, 0x78(r31)
		mr	  r9, r3
		rlwinm	  r8, r3, 24,16,23
		insrwi	  r9, r3, 16,0
		extlwi	  r7, r9, 16,8
		or	  r6, r7, r8
		or	  r5, r6, r11
		stw	  r5, 0x78(r31)
		lwz	  r4, 0x7C(r31)
		lbz	  r3, 0x7C(r31)
		mr	  r11, r4
		rlwinm	  r9, r4, 24,16,23
		insrwi	  r11, r4, 16,0
		extlwi	  r8, r11, 16,8
		or	  r7, r8, r9
		or	  r6, r7, r3
		stw	  r6, 0x7C(r31)
		lwz	  r5, 0xE8(r31)
		lbz	  r4, 0xE8(r31)
		mr	  r3, r5
		rlwinm	  r11, r5, 24,16,23
		insrwi	  r3, r5, 16,0
		extlwi	  r9, r3, 16,8
		or	  r8, r9, r11
		or	  r7, r8, r4
		stw	  r7, 0xE8(r31)
		bne	  cr6, loc_8256B2F4
		lwz	  r10, 0xEC(r31)

loc_8256B2F4:				// CODE XREF: sub_82568170+317Cj
		lwz	  r11, 0xEC(r31)
		cmpwi	  cr6, r29, 0
		lbz	  r9, 0xEC(r31)
		mr	  r8, r11
		rlwinm	  r7, r11, 24,16,23
		insrwi	  r8, r11, 16,0
		extlwi	  r6, r8, 16,8
		or	  r5, r6, r7
		or	  r11, r5, r9
		stw	  r11, 0xEC(r31)
		bne	  cr6, loc_8256B324
		mr	  r10, r11

loc_8256B324:				// CODE XREF: sub_82568170+31ACj
		lwz	  r9, 0x280(r31)
		addi	  r11, r31, 0x284
		lbz	  r8, 0x280(r31)
		cmplwi	  cr6, r10, 0
		mr	  r7, r9
		rlwinm	  r6, r9, 24,16,23
		insrwi	  r7, r9, 16,0
		extlwi	  r5, r7, 16,8
		or	  r4, r5, r6
		or	  r3, r4, r8
		stw	  r3, 0x280(r31)
		beq	  cr6, loc_8256B3B8
		mtspr	CTR, r10
		addi	  r11, r11, -4

loc_8256B35C:				// CODE XREF: sub_82568170+3244j
		lhz	  r9, 4(r11)
		lbz	  r10, 4(r11)
		insrwi	  r10, r9, 16,8
		sth	  r10, 4(r11)
		lhz	  r6, 6(r11)
		lbz	  r7, 6(r11)
		insrwi	  r7, r6, 16,8
		sth	  r7, 6(r11)
		lhz	  r3, 0xA(r11)
		lbz	  r4, 0xA(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0xA(r11)
		lwz	  r9, 0xC(r11)
		mr	  r7, r9
		insrwi	  r7, r9, 16,0
		lbz	  r8, 0xC(r11)
		rlwinm	  r6, r9, 24,16,23
		extlwi	  r4, r7, 16,8
		mr	  r5, r8
		or	  r3, r4, r6
		or	  r10, r3, r8
		stwu	  r10, 0xC(r11)
		bdnz	  loc_8256B35C

loc_8256B3B8:				// CODE XREF: sub_82568170+31E0j
		lhzu	  r10, 0x8E0(r31)
		li	  r11, 4
		rotlwi	  r9, r10, 8
		lbz	  r8, 0(r31)
		mtspr	CTR, r11
		or	  r7, r9, r8
		sth	  r7, 0(r31)
		lhzu	  r5, 2(r31)
		rotlwi	  r4, r5, 8
		lbz	  r3, 0(r31)
		or	  r11, r4, r3
		sth	  r11, 0(r31)
		lhzu	  r9, 2(r31)
		rotlwi	  r8, r9, 8
		lbz	  r7, 0(r31)
		or	  r6, r8, r7
		sth	  r6, 0(r31)
		lhzu	  r4, 2(r31)
		rotlwi	  r3, r4, 8
		lbz	  r11, 0(r31)
		or	  r10, r3, r11
		sth	  r10, 0(r31)
		lhzu	  r8, 2(r31)
		rotlwi	  r7, r8, 8
		lbz	  r6, 0(r31)
		or	  r5, r7, r6
		sth	  r5, 0(r31)
		lhzu	  r3, 2(r31)
		rotlwi	  r11, r3, 8
		lbz	  r10, 0(r31)
		or	  r9, r11, r10
		sth	  r9, 0(r31)
		lhzu	  r7, 2(r31)
		rotlwi	  r6, r7, 8
		lbz	  r5, 0(r31)
		or	  r4, r6, r5
		sth	  r4, 0(r31)
		lhzu	  r11, 2(r31)
		rotlwi	  r10, r11, 8
		lbz	  r9, 0(r31)
		or	  r8, r10, r9
		sth	  r8, 0(r31)
		lhzu	  r6, 2(r31)
		rotlwi	  r5, r6, 8
		lbz	  r4, 0(r31)
		or	  r3, r5, r4
		sth	  r3, 0(r31)
		lhzu	  r10, 2(r31)
		rotlwi	  r9, r10, 8
		addi	  r11, r31, 2
		lbz	  r8, 0(r31)
		or	  r7, r9, r8
		sth	  r7, 0(r31)

loc_8256B48C:				// CODE XREF: sub_82568170+33D4j
		lwz	  r10, 0(r11)
		lwz	  r9, 4(r11)
		lwz	  r8, 8(r11)
		mr	  r7, r10
		lwz	  r6, 0xC(r11)
		mr	  r5, r9
		mr	  r3, r8
		lwz	  r4, 0x10(r11)
		insrwi	  r7, r10, 16,0
		lbz	  r31, 0(r11)
		mr	  r30, r6
		lbz	  r29, 0xC(r11)
		insrwi	  r5, r9, 16,0
		lbz	  r28, 4(r11)
		insrwi	  r3, r8, 16,0
		lbz	  r26, 8(r11)
		extlwi	  r7, r7, 16,8
		lbz	  r25, 0x10(r11)
		rlwinm	  r10, r10, 24,16,23
		mr	  r27, r4
		insrwi	  r30, r6, 16,0
		rlwinm	  r8, r8, 24,16,23
		extlwi	  r5, r5, 16,8
		rlwinm	  r9, r9, 24,16,23
		extlwi	  r3, r3, 16,8
		or	  r7, r7, r10
		insrwi	  r27, r4, 16,0
		extlwi	  r10, r30, 16,8
		or	  r9, r5, r9
		or	  r3, r3, r8
		or	  r8, r7, r31
		extlwi	  r5, r27, 16,8
		rlwinm	  r4, r4, 24,16,23
		stw	  r8, 0(r11)
		or	  r7, r10, r29
		rlwinm	  r6, r6, 24,16,23
		or	  r10, r9, r28
		or	  r9, r5, r4
		or	  r8, r3, r26
		stw	  r10, 4(r11)
		or	  r7, r7, r6
		or	  r6, r9, r25
		stw	  r8, 8(r11)
		stw	  r7, 0xC(r11)
		stw	  r6, 0x10(r11)
		addi	  r11, r11, 0x14
		bdnz	  loc_8256B48C
		li	  r10, 4
		mtspr	CTR, r10

loc_8256B550:				// CODE XREF: sub_82568170+3498j
		lwz	  r10, 0(r11)
		lwz	  r9, 4(r11)
		lwz	  r8, 8(r11)
		mr	  r7, r10
		lwz	  r6, 0xC(r11)
		mr	  r5, r9
		mr	  r3, r8
		lwz	  r4, 0x10(r11)
		insrwi	  r7, r10, 16,0
		lbz	  r31, 0(r11)
		mr	  r30, r6
		lbz	  r29, 4(r11)
		insrwi	  r5, r9, 16,0
		lbz	  r28, 8(r11)
		insrwi	  r3, r8, 16,0
		lbz	  r26, 0xC(r11)
		mr	  r27, r4
		lbz	  r25, 0x10(r11)
		rlwinm	  r10, r10, 24,16,23
		extlwi	  r7, r7, 16,8
		insrwi	  r30, r6, 16,0
		extlwi	  r5, r5, 16,8
		rlwinm	  r9, r9, 24,16,23
		extlwi	  r3, r3, 16,8
		rlwinm	  r8, r8, 24,16,23
		or	  r7, r7, r10
		insrwi	  r27, r4, 16,0
		extlwi	  r10, r30, 16,8
		rlwinm	  r6, r6, 24,16,23
		or	  r5, r5, r9
		or	  r3, r3, r8
		rlwinm	  r4, r4, 24,16,23
		or	  r8, r7, r31
		extlwi	  r9, r27, 16,8
		or	  r7, r10, r6
		stw	  r8, 0(r11)
		or	  r6, r5, r29
		or	  r5, r9, r4
		or	  r4, r3, r28
		stw	  r6, 4(r11)
		or	  r3, r7, r26
		or	  r10, r5, r25
		stw	  r4, 8(r11)
		stw	  r3, 0xC(r11)
		stw	  r10, 0x10(r11)
		addi	  r11, r11, 0x14
		bdnz	  loc_8256B550
		lhz	  r9, 0(r11)
		li	  r10, 0xA
		lbz	  r8, 0(r11)
		rotlwi	  r7, r9, 8
		or	  r6, r7, r8
		mtspr	CTR, r10
		sth	  r6, 0(r11)
		lhzu	  r4, 2(r11)
		rotlwi	  r3, r4, 8
		lbz	  r10, 0(r11)
		or	  r9, r3, r10
		sth	  r9, 0(r11)
		lhzu	  r7, 2(r11)
		rotlwi	  r6, r7, 8
		lbz	  r5, 0(r11)
		or	  r4, r6, r5
		sth	  r4, 0(r11)
		lhzu	  r10, 2(r11)
		rotlwi	  r9, r10, 8
		lbz	  r8, 0(r11)
		or	  r7, r9, r8
		sth	  r7, 0(r11)
		lhzu	  r5, 2(r11)
		rotlwi	  r4, r5, 8
		lbz	  r3, 0(r11)
		or	  r10, r4, r3
		sth	  r10, 0(r11)
		lhzu	  r8, 2(r11)
		rotlwi	  r7, r8, 8
		lbz	  r6, 0(r11)
		or	  r5, r7, r6
		sth	  r5, 0(r11)
		lhzu	  r3, 2(r11)
		rotlwi	  r10, r3, 8
		lbz	  r9, 0(r11)
		or	  r8, r10, r9
		sth	  r8, 0(r11)
		lhzu	  r6, 0x16(r11)
		rotlwi	  r5, r6, 8
		addi	  r10, r11, 2
		lbz	  r4, 0(r11)
		or	  r3, r5, r4
		sth	  r3, 0(r11)
		addi	  r11, r10, -4

loc_8256B6BC:				// CODE XREF: sub_82568170+376Cj
		lwz	  r9, 8(r11)
		lbz	  r5, 8(r11)
		mr	  r7, r9
		rlwinm	  r6, r9, 24,16,23
		insrwi	  r7, r9, 16,0
		extlwi	  r4, r7, 16,8
		or	  r3, r4, r6
		or	  r9, r3, r5
		stw	  r9, 8(r11)
		lwz	  r8, 0xC(r11)
		lbz	  r4, 0xC(r11)
		mr	  r6, r8
		rlwinm	  r5, r8, 24,16,23
		insrwi	  r6, r8, 16,0
		extlwi	  r3, r6, 16,8
		or	  r9, r3, r5
		or	  r8, r9, r4
		stw	  r8, 0xC(r11)
		lwz	  r7, 0x10(r11)
		lbz	  r3, 0x10(r11)
		mr	  r5, r7
		rlwinm	  r4, r7, 24,16,23
		insrwi	  r5, r7, 16,0
		extlwi	  r9, r5, 16,8
		or	  r8, r9, r4
		or	  r7, r8, r3
		stw	  r7, 0x10(r11)
		lwz	  r6, 0x18(r11)
		lbz	  r9, 0x18(r11)
		mr	  r4, r6
		rlwinm	  r3, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r8, r4, 16,8
		or	  r7, r8, r3
		or	  r6, r7, r9
		stw	  r6, 0x18(r11)
		lwz	  r5, 0x1C(r11)
		lbz	  r8, 0x1C(r11)
		mr	  r3, r5
		rlwinm	  r9, r5, 24,16,23
		insrwi	  r3, r5, 16,0
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0x1C(r11)
		lwz	  r4, 0x20(r11)
		lbz	  r7, 0x20(r11)
		mr	  r9, r4
		rlwinm	  r8, r4, 24,16,23
		insrwi	  r9, r4, 16,0
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r8
		or	  r4, r5, r7
		stw	  r4, 0x20(r11)
		lwz	  r3, 0x28(r11)
		lbz	  r6, 0x28(r11)
		mr	  r8, r3
		rlwinm	  r7, r3, 24,16,23
		insrwi	  r8, r3, 16,0
		extlwi	  r5, r8, 16,8
		or	  r4, r5, r7
		or	  r3, r4, r6
		stw	  r3, 0x28(r11)
		lwz	  r9, 0x2C(r11)
		lbz	  r5, 0x2C(r11)
		mr	  r7, r9
		rlwinm	  r6, r9, 24,16,23
		insrwi	  r7, r9, 16,0
		extlwi	  r4, r7, 16,8
		or	  r3, r4, r6
		or	  r9, r3, r5
		stw	  r9, 0x2C(r11)
		lwz	  r8, 0x30(r11)
		lbz	  r4, 0x30(r11)
		mr	  r7, r8
		rlwinm	  r5, r8, 24,16,23
		insrwi	  r7, r8, 16,0
		extlwi	  r3, r7, 16,8
		or	  r9, r3, r5
		or	  r8, r9, r4
		stw	  r8, 0x30(r11)
		lwz	  r7, 0x38(r11)
		lbz	  r3, 0x38(r11)
		mr	  r5, r7
		rlwinm	  r4, r7, 24,16,23
		insrwi	  r5, r7, 16,0
		extlwi	  r9, r5, 16,8
		or	  r8, r9, r4
		or	  r7, r8, r3
		stw	  r7, 0x38(r11)
		lwz	  r6, 0x3C(r11)
		lbz	  r9, 0x3C(r11)
		mr	  r4, r6
		rlwinm	  r3, r6, 24,16,23
		insrwi	  r4, r6, 16,0
		extlwi	  r8, r4, 16,8
		or	  r7, r8, r3
		or	  r6, r7, r9
		stw	  r6, 0x3C(r11)
		lwz	  r5, 0x40(r11)
		lbz	  r8, 0x40(r11)
		mr	  r3, r5
		rlwinm	  r9, r5, 24,16,23
		insrwi	  r3, r5, 16,0
		extlwi	  r7, r3, 16,8
		or	  r6, r7, r9
		or	  r5, r6, r8
		stw	  r5, 0x40(r11)
		lwz	  r4, 0x48(r11)
		lbz	  r7, 0x48(r11)
		mr	  r9, r4
		rlwinm	  r8, r4, 24,16,23
		insrwi	  r9, r4, 16,0
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r8
		or	  r4, r5, r7
		stw	  r4, 0x48(r11)
		lwz	  r3, 0x4C(r11)
		lbz	  r6, 0x4C(r11)
		mr	  r8, r3
		rlwinm	  r7, r3, 24,16,23
		insrwi	  r8, r3, 16,0
		extlwi	  r5, r8, 16,8
		or	  r4, r5, r7
		or	  r3, r4, r6
		stw	  r3, 0x4C(r11)
		lwz	  r9, 0x50(r11)
		lbz	  r8, 0x50(r11)
		mr	  r7, r9
		rlwinm	  r6, r9, 24,16,23
		insrwi	  r7, r9, 16,0
		mr	  r5, r8
		extlwi	  r4, r7, 16,8
		or	  r3, r4, r6
		or	  r9, r3, r8
		stwu	  r9, 0x50(r11)
		bdnz	  loc_8256B6BC
		addi	  r7, r10, 0x600
		li	  r10, 0x80
		addi	  r11, r7, 0x80
		lwz	  r9, 0x80(r7)
		lbz	  r8, 0x80(r7)
		mtspr	CTR, r10
		mr	  r6, r9
		rlwinm	  r5, r9, 24,16,23
		insrwi	  r6, r9, 16,0
		extlwi	  r4, r6, 16,8
		or	  r3, r4, r5
		or	  r10, r3, r8
		stw	  r10, 0x80(r7)
		lwzu	  r10, 4(r11)
		mr	  r9, r10
		rlwinm	  r8, r10, 24,16,23
		insrwi	  r9, r10, 16,0
		lbz	  r6, 0(r11)
		addi	  r10, r11, 4
		extlwi	  r5, r9, 16,8
		or	  r4, r5, r8
		or	  r3, r4, r6
		stw	  r3, 0(r11)
		addi	  r11, r10, -4

loc_8256B940:				// CODE XREF: sub_82568170+38CCj
		lhz	  r8, 4(r11)
		lbz	  r9, 4(r11)
		insrwi	  r9, r8, 16,8
		sth	  r9, 4(r11)
		lhz	  r4, 6(r11)
		lbz	  r5, 6(r11)
		insrwi	  r5, r4, 16,8
		sth	  r5, 6(r11)
		lhz	  r8, 8(r11)
		lbz	  r9, 8(r11)
		insrwi	  r9, r8, 16,8
		sth	  r9, 8(r11)
		lbz	  r5, 0xA(r11)
		lhz	  r4, 0xA(r11)
		insrwi	  r5, r4, 16,8
		sth	  r5, 0xA(r11)
		lhz	  r8, 0xC(r11)
		lbz	  r9, 0xC(r11)
		insrwi	  r9, r8, 16,8
		sth	  r9, 0xC(r11)
		lhz	  r4, 0xE(r11)
		lbz	  r5, 0xE(r11)
		insrwi	  r5, r4, 16,8
		sth	  r5, 0xE(r11)
		lhz	  r8, 0x10(r11)
		lbz	  r9, 0x10(r11)
		insrwi	  r9, r8, 16,8
		sth	  r9, 0x10(r11)
		lhz	  r4, 0x12(r11)
		lbz	  r5, 0x12(r11)
		insrwi	  r5, r4, 16,8
		sth	  r5, 0x12(r11)
		lwz	  r9, 0x14(r11)
		lbz	  r4, 0x14(r11)
		mr	  r6, r9
		rlwinm	  r5, r9, 24,16,23
		insrwi	  r6, r9, 16,0
		extlwi	  r3, r6, 16,8
		or	  r9, r3, r5
		or	  r8, r9, r4
		stw	  r8, 0x14(r11)
		lhz	  r5, 0x18(r11)
		lbz	  r6, 0x18(r11)
		insrwi	  r6, r5, 16,8
		sth	  r6, 0x18(r11)
		lhz	  r9, 0x1A(r11)
		lbz	  r3, 0x1A(r11)
		insrwi	  r3, r9, 16,8
		sth	  r3, 0x1A(r11)
		lhz	  r5, 0x1C(r11)
		lbz	  r6, 0x1C(r11)
		insrwi	  r6, r5, 16,8
		sth	  r6, 0x1C(r11)
		lbz	  r3, 0x1E(r11)
		lhz	  r9, 0x1E(r11)
		insrwi	  r3, r9, 16,8
		clrlwi	  r8, r3, 16
		sth	  r8, 0x1E(r11)
		lbz	  r6, 0x20(r11)
		lhz	  r5, 0x20(r11)
		insrwi	  r6, r5, 16,8
		clrlwi	  r4, r6, 16
		sthu	  r4, 0x20(r11)
		bdnz	  loc_8256B940
		addi	  r4, r10, 0x1000
		li	  r5, 8
		addi	  r9, r4, 4

loc_8256BA4C:				// CODE XREF: sub_82568170+3C6Cj
		lhz	  r11, -4(r9)
		li	  r6, 8
		lbz	  r3, -4(r9)
		addi	  r8, r9, 0xC
		rotlwi	  r11, r11, 8
		addi	  r10, r9, 0x1A
		or	  r3, r11, r3
		mtspr	CTR, r6
		addi	  r11, r9, -0x10
		sth	  r3, -4(r9)
		lhz	  r3, -2(r9)
		lbz	  r6, -2(r9)
		rotlwi	  r3, r3, 8
		or	  r6, r3, r6
		sth	  r6, -2(r9)
		lwz	  r6, 0(r9)
		lbz	  r3, 0(r9)
		mr	  r31, r6
		rlwinm	  r30, r6, 24,16,23
		insrwi	  r31, r6, 16,0
		extlwi	  r6, r31, 16,8
		or	  r6, r6, r30
		or	  r3, r6, r3
		stw	  r3, 0(r9)
		lhz	  r6, 4(r9)
		lbz	  r3, 4(r9)
		rotlwi	  r6, r6, 8
		or	  r3, r6, r3
		sth	  r3, 4(r9)
		lhz	  r3, 6(r9)
		lbz	  r6, 6(r9)
		rotlwi	  r3, r3, 8
		or	  r6, r3, r6
		sth	  r6, 6(r9)
		lwz	  r6, 8(r9)
		lbz	  r3, 8(r9)
		mr	  r31, r6
		rlwinm	  r30, r6, 24,16,23
		insrwi	  r31, r6, 16,0
		extlwi	  r6, r31, 16,8
		or	  r6, r6, r30
		or	  r3, r6, r3
		stw	  r3, 8(r9)
		lwz	  r6, 0xC(r9)
		lbz	  r3, 0xC(r9)
		mr	  r31, r6
		rlwinm	  r30, r6, 24,16,23
		insrwi	  r31, r6, 16,0
		extlwi	  r6, r31, 16,8
		or	  r6, r6, r30
		or	  r3, r6, r3
		stw	  r3, 0xC(r9)

loc_8256BB1C:				// CODE XREF: sub_82568170+3C60j
		ld	  r31, 0x3C(r11)
		lbz	  r6, 0x42(r11)
		lbz	  r3, 0x41(r11)
		insrdi	  r6, r31, 56,0
		lbz	  r30, 0x40(r11)
		lbz	  r31, 0x3F(r11)
		insrdi	  r3, r6, 56,0
		lbz	  r29, 0x3E(r11)
		lbz	  r6, 0x3D(r11)
		insrdi	  r30, r3, 56,0
		lbz	  r28, 0x3C(r11)
		mr	  r3, r29
		insrdi	  r31, r30, 56,0
		insrdi	  r3, r31, 56,0
		mr	  r31, r28
		insrdi	  r6, r3, 56,0
		insrdi	  r31, r6, 56,0
		std	  r31, 0x3C(r11)
		lwz	  r3, 0x44(r11)
		lbz	  r6, 0x44(r11)
		mr	  r31, r3
		rlwinm	  r30, r3, 24,16,23
		insrwi	  r31, r3, 16,0
		mr	  r3, r6
		extlwi	  r6, r31, 16,8
		or	  r6, r6, r30
		or	  r3, r6, r3
		stw	  r3, 0x44(r11)
		lwz	  r6, 0x48(r11)
		lbz	  r3, 0x48(r11)
		mr	  r31, r6
		rlwinm	  r30, r6, 24,16,23
		insrwi	  r31, r6, 16,0
		mr	  r6, r3
		extlwi	  r3, r31, 16,8
		or	  r3, r3, r30
		or	  r6, r3, r6
		stw	  r6, 0x48(r11)
		lhz	  r6, 0x4C(r11)
		lbz	  r3, 0x4C(r11)
		insrwi	  r3, r6, 16,8
		sth	  r3, 0x4C(r11)
		lhz	  r3, 0x4E(r11)
		lbz	  r6, 0x4E(r11)
		insrwi	  r6, r3, 16,8
		sth	  r6, 0x4E(r11)
		lhz	  r6, 0x50(r11)
		lbz	  r3, 0x50(r11)
		insrwi	  r3, r6, 16,8
		sth	  r3, 0x50(r11)
		lhz	  r3, 0x52(r11)
		lbz	  r6, 0x52(r11)
		insrwi	  r6, r3, 16,8
		sth	  r6, 0x52(r11)
		lhz	  r6, 0x54(r11)
		lbz	  r3, 0x54(r11)
		insrwi	  r3, r6, 16,8
		sth	  r3, 0x54(r11)
		lhz	  r3, 0x56(r11)
		lbz	  r6, 0x56(r11)
		insrwi	  r6, r3, 16,8
		sth	  r6, 0x56(r11)
		lhz	  r6, 0x58(r11)
		lbz	  r3, 0x58(r11)
		insrwi	  r3, r6, 16,8
		sth	  r3, 0x58(r11)
		lbz	  r6, 0x5A(r11)
		lhz	  r3, 0x5A(r11)
		insrwi	  r6, r3, 16,8
		sth	  r6, 0x5A(r11)
		lbz	  r6, 0x5C(r11)
		lhz	  r3, 0x5C(r11)
		insrwi	  r6, r3, 16,8
		sth	  r6, 0x5C(r11)
		lbz	  r3, 0x60(r11)
		lwz	  r6, 0x60(r11)
		mr	  r31, r6
		insrwi	  r31, r6, 16,0
		rlwinm	  r30, r6, 24,16,23
		mr	  r6, r3
		extlwi	  r3, r31, 16,8
		or	  r3, r3, r30
		or	  r6, r3, r6
		stwu	  r6, 0x60(r11)
		lwz	  r3, 0x48(r8)
		lbz	  r6, 0x48(r8)
		mr	  r31, r3
		rlwinm	  r30, r3, 24,16,23
		insrwi	  r31, r3, 16,0
		mr	  r3, r6
		extlwi	  r6, r31, 16,8
		or	  r6, r6, r30
		or	  r3, r6, r3
		stw	  r3, 0x48(r8)
		lhz	  r3, 0x42(r10)
		lbz	  r6, 0x42(r10)
		insrwi	  r6, r3, 16,8
		sth	  r6, 0x42(r10)
		lhz	  r6, 0x46(r10)
		lbz	  r3, 0x46(r10)
		insrwi	  r3, r6, 16,8
		sth	  r3, 0x46(r10)
		lhz	  r3, 0x4A(r10)
		lbz	  r6, 0x4A(r10)
		insrwi	  r6, r3, 16,8
		sth	  r6, 0x4A(r10)
		lwz	  r3, 0x4C(r8)
		lbz	  r6, 0x4C(r8)
		mr	  r31, r3
		rlwinm	  r30, r3, 24,16,23
		insrwi	  r31, r3, 16,0
		mr	  r3, r6
		extlwi	  r6, r31, 16,8
		or	  r6, r6, r30
		or	  r3, r6, r3
		stw	  r3, 0x4C(r8)
		lhz	  r3, 0x44(r10)
		lbz	  r6, 0x44(r10)
		insrwi	  r6, r3, 16,8
		sth	  r6, 0x44(r10)
		lhz	  r6, 0x48(r10)
		lbz	  r3, 0x48(r10)
		insrwi	  r3, r6, 16,8
		sth	  r3, 0x48(r10)
		lhz	  r3, 0x4C(r10)
		lbz	  r6, 0x4C(r10)
		insrwi	  r6, r3, 16,8
		sth	  r6, 0x4C(r10)
		lwz	  r3, 0x5C(r8)
		lbz	  r6, 0x5C(r8)
		mr	  r31, r3
		rlwinm	  r30, r3, 24,16,23
		insrwi	  r31, r3, 16,0
		mr	  r3, r6
		extlwi	  r6, r31, 16,8
		or	  r6, r6, r30
		or	  r3, r6, r3
		stw	  r3, 0x5C(r8)
		lhz	  r3, 0x56(r10)
		lbz	  r6, 0x56(r10)
		insrwi	  r6, r3, 16,8
		sth	  r6, 0x56(r10)
		lhz	  r6, 0x5A(r10)
		lbz	  r3, 0x5A(r10)
		insrwi	  r3, r6, 16,8
		sth	  r3, 0x5A(r10)
		lhz	  r3, 0x5E(r10)
		lbz	  r6, 0x5E(r10)
		insrwi	  r6, r3, 16,8
		sth	  r6, 0x5E(r10)
		lbz	  r6, 0x60(r8)
		lwz	  r3, 0x60(r8)
		mr	  r31, r3
		insrwi	  r31, r3, 16,0
		rlwinm	  r30, r3, 24,16,23
		mr	  r3, r6
		extlwi	  r6, r31, 16,8
		or	  r6, r6, r30
		or	  r3, r6, r3
		stwu	  r3, 0x60(r8)
		lbz	  r6, 0x58(r10)
		lhz	  r3, 0x58(r10)
		insrwi	  r6, r3, 16,8
		sth	  r6, 0x58(r10)
		lhz	  r6, 0x5C(r10)
		lbz	  r3, 0x5C(r10)
		insrwi	  r3, r6, 16,8
		sth	  r3, 0x5C(r10)
		lbz	  r6, 0x60(r10)
		lhz	  r3, 0x60(r10)
		insrwi	  r6, r3, 16,8
		clrlwi	  r6, r6, 16
		sthu	  r6, 0x60(r10)
		bdnz	  loc_8256BB1C
		addic.	  r5, r5, -1
		addi	  r9, r9, 0x320
		bne	  loc_8256BA4C
		addi	  r8, r4, 0x1900
		li	  r5, 8
		addi	  r9, r8, 4

loc_8256BDEC:				// CODE XREF: sub_82568170+3EF0j
		lhz	  r10, -4(r9)
		li	  r6, 8
		lbz	  r4, -4(r9)
		addi	  r11, r9, -2
		rotlwi	  r3, r10, 8
		addi	  r10, r9, 6
		or	  r4, r3, r4
		mtspr	CTR, r6
		sth	  r4, -4(r9)
		lhz	  r6, -2(r9)
		lbz	  r4, -2(r9)
		rotlwi	  r3, r6, 8
		or	  r6, r3, r4
		sth	  r6, -2(r9)
		lwz	  r3, 0(r9)
		lbz	  r6, 0(r9)
		mr	  r4, r3
		rlwinm	  r31, r3, 24,16,23
		insrwi	  r4, r3, 16,0
		extlwi	  r3, r4, 16,8
		or	  r4, r3, r31
		or	  r3, r4, r6
		stw	  r3, 0(r9)
		lhz	  r6, 4(r9)
		lbz	  r4, 4(r9)
		rotlwi	  r3, r6, 8
		or	  r6, r3, r4
		sth	  r6, 4(r9)
		lhz	  r3, 6(r9)
		lbz	  r6, 6(r9)
		rotlwi	  r4, r3, 8
		or	  r3, r4, r6
		sth	  r3, 6(r9)
		lwz	  r4, 8(r9)
		lbz	  r3, 8(r9)
		mr	  r6, r4
		rlwinm	  r31, r4, 24,16,23
		insrwi	  r6, r4, 16,0
		extlwi	  r4, r6, 16,8
		or	  r6, r4, r31
		or	  r4, r6, r3
		stw	  r4, 8(r9)
		lwz	  r3, 0xC(r9)
		lbz	  r6, 0xC(r9)
		mr	  r4, r3
		rlwinm	  r31, r3, 24,16,23
		insrwi	  r4, r3, 16,0
		extlwi	  r3, r4, 16,8
		or	  r4, r3, r31
		or	  r3, r4, r6
		stw	  r3, 0xC(r9)

loc_8256BEB8:				// CODE XREF: sub_82568170+3EE4j
		lwz	  r6, 0x12(r11)
		lbz	  r4, 0x12(r11)
		mr	  r3, r6
		rlwinm	  r31, r6, 24,16,23
		insrwi	  r3, r6, 16,0
		mr	  r6, r4
		extlwi	  r4, r3, 16,8
		or	  r3, r4, r31
		or	  r6, r3, r6
		stw	  r6, 0x12(r11)
		lhz	  r3, 0x16(r11)
		lbz	  r4, 0x16(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x16(r11)
		lhz	  r3, 0x18(r11)
		lbz	  r4, 0x18(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x18(r11)
		lhz	  r3, 0x1A(r11)
		lbz	  r4, 0x1A(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x1A(r11)
		lhz	  r3, 0x2E(r11)
		lbz	  r4, 0x2E(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x2E(r11)
		lhz	  r3, 0x30(r11)
		lbz	  r4, 0x30(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x30(r11)
		lhz	  r3, 0x32(r11)
		lbz	  r4, 0x32(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x32(r11)
		lhz	  r3, 0x34(r11)
		lbz	  r4, 0x34(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x34(r11)
		lhz	  r3, 0x2E(r10)
		lbz	  r4, 0x2E(r10)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x2E(r10)
		lhz	  r3, 0x30(r10)
		lbz	  r4, 0x30(r10)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x30(r10)
		lbz	  r4, 0x32(r10)
		lhz	  r3, 0x32(r10)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x32(r10)
		lhz	  r3, 0x34(r10)
		lbz	  r4, 0x34(r10)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x34(r10)
		lhz	  r3, 0x3E(r11)
		lbz	  r4, 0x3E(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x3E(r11)
		lbz	  r4, 0x40(r11)
		lhz	  r3, 0x40(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x40(r11)
		lbz	  r4, 0x42(r11)
		lhz	  r3, 0x42(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x42(r11)
		lhz	  r3, 0x44(r11)
		lbz	  r4, 0x44(r11)
		insrwi	  r4, r3, 16,8
		sthu	  r4, 0x44(r11)
		lhz	  r3, 0x3E(r10)
		lbz	  r4, 0x3E(r10)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x3E(r10)
		lhz	  r3, 0x46(r10)
		lbz	  r4, 0x46(r10)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x46(r10)
		lbz	  r4, 0x4A(r10)
		lhz	  r3, 0x4A(r10)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x4A(r10)
		lhz	  r3, 0x40(r10)
		lbz	  r4, 0x40(r10)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x40(r10)
		lhz	  r3, 0x48(r10)
		lbz	  r4, 0x48(r10)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x48(r10)
		lhz	  r3, 0x4C(r10)
		lbz	  r4, 0x4C(r10)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x4C(r10)
		lhz	  r3, 0x42(r10)
		lbz	  r4, 0x42(r10)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x42(r10)
		lbz	  r4, 0x44(r10)
		lhz	  r3, 0x44(r10)
		insrwi	  r4, r3, 16,8
		clrlwi	  r6, r4, 16
		sthu	  r6, 0x44(r10)
		bdnz	  loc_8256BEB8
		addic.	  r5, r5, -1
		addi	  r9, r9, 0x234
		bne	  loc_8256BDEC
		lwzu	  r11, 0x11A0(r8)
		mr	  r10, r11
		rlwinm	  r9, r11, 24,16,23
		insrwi	  r10, r11, 16,0
		lbz	  r6, 0(r8)
		extlwi	  r5, r10, 16,8
		or	  r4, r5, r9
		or	  r3, r4, r6
		stw	  r3, 0(r8)
		lwzu	  r11, 4(r8)
		mr	  r10, r11
		rlwinm	  r9, r11, 24,16,23
		insrwi	  r10, r11, 16,0
		lbz	  r6, 0(r8)
		extlwi	  r5, r10, 16,8
		or	  r4, r5, r9
		or	  r3, r4, r6
		stw	  r3, 0(r8)
		lwzu	  r11, 4(r8)
		mr	  r10, r11
		rlwinm	  r9, r11, 24,16,23
		insrwi	  r10, r11, 16,0
		lbz	  r6, 0(r8)
		extlwi	  r5, r10, 16,8
		or	  r4, r5, r9
		or	  r3, r4, r6
		stw	  r3, 0(r8)
		lwzu	  r11, 0x3C00(r7)
		mr	  r10, r11
		rlwinm	  r9, r11, 24,16,23
		insrwi	  r10, r11, 16,0
		lbz	  r8, 0(r7)
		extlwi	  r6, r10, 16,8
		or	  r5, r6, r9
		or	  r4, r5, r8
		stw	  r4, 0(r7)
		lwzu	  r11, 4(r7)
		mr	  r3, r11
		rlwinm	  r10, r11, 24,16,23
		insrwi	  r3, r11, 16,0
		lbz	  r9, 0(r7)
		extlwi	  r8, r3, 16,8
		or	  r6, r8, r10
		or	  r5, r6, r9
		stw	  r5, 0(r7)
		lwzu	  r11, 0x44(r7)
		mr	  r4, r11
		rlwinm	  r3, r11, 24,16,23
		insrwi	  r4, r11, 16,0
		lbz	  r11, 0(r7)
		addic.	  r8, r7, 4
		extlwi	  r10, r4, 16,8
		or	  r9, r10, r3
		or	  r6, r9, r11
		stw	  r6, 0(r7)
		beq	  loc_8256C168
		lwz	  r11, 0(r8)
		lbz	  r10, 0(r8)
		mr	  r9, r11
		rlwinm	  r7, r11, 24,16,23
		insrwi	  r9, r11, 16,0
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r7
		or	  r4, r5, r10
		stw	  r4, 0(r8)

loc_8256C168:				// CODE XREF: sub_82568170+3FD0j
		addic.	  r11, r8, 0x184
		beq	  loc_8256C254
		li	  r10, 0x12
		addi	  r11, r11, -2
		mtspr	CTR, r10

loc_8256C17C:				// CODE XREF: sub_82568170+40E0j
		lwz	  r10, 2(r11)
		lbz	  r5, 2(r11)
		mr	  r7, r10
		rlwinm	  r6, r10, 24,16,23
		insrwi	  r7, r10, 16,0
		extlwi	  r4, r7, 16,8
		or	  r3, r4, r6
		or	  r10, r3, r5
		stw	  r10, 2(r11)
		lwz	  r9, 6(r11)
		lbz	  r4, 6(r11)
		mr	  r6, r9
		rlwinm	  r5, r9, 24,16,23
		insrwi	  r6, r9, 16,0
		extlwi	  r3, r6, 16,8
		or	  r10, r3, r5
		or	  r9, r10, r4
		stw	  r9, 6(r11)
		lhz	  r6, 0xA(r11)
		lbz	  r7, 0xA(r11)
		insrwi	  r7, r6, 16,8
		sth	  r7, 0xA(r11)
		lhz	  r3, 0xC(r11)
		lbz	  r4, 0xC(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0xC(r11)
		lhz	  r7, 0xE(r11)
		lbz	  r9, 0xE(r11)
		insrwi	  r9, r7, 16,8
		sth	  r9, 0xE(r11)
		lhz	  r4, 0x10(r11)
		lbz	  r5, 0x10(r11)
		insrwi	  r5, r4, 16,8
		sth	  r5, 0x10(r11)
		lhz	  r9, 0x12(r11)
		lbz	  r10, 0x12(r11)
		insrwi	  r10, r9, 16,8
		sth	  r10, 0x12(r11)
		lhz	  r5, 0x14(r11)
		lbz	  r6, 0x14(r11)
		insrwi	  r6, r5, 16,8
		clrlwi	  r4, r6, 16
		sth	  r4, 0x14(r11)
		lbz	  r3, 0x16(r11)
		lhz	  r10, 0x16(r11)
		insrwi	  r3, r10, 16,8
		clrlwi	  r9, r3, 16
		sth	  r9, 0x16(r11)
		lbz	  r7, 0x18(r11)
		lhz	  r6, 0x18(r11)
		insrwi	  r7, r6, 16,8
		clrlwi	  r5, r7, 16
		sthu	  r5, 0x18(r11)
		bdnz	  loc_8256C17C

loc_8256C254:				// CODE XREF: sub_82568170+3FFCj
		addic.	  r10, r8, 0x334
		beq	  loc_8256C350
		li	  r7, 8

loc_8256C260:				// CODE XREF: sub_82568170+41DCj
		lhz	  r6, 0(r10)
		li	  r9, 0x12
		lbz	  r5, 0(r10)
		addi	  r11, r10, -0x3E
		rotlwi	  r4, r6, 8
		or	  r3, r4, r5
		mtspr	CTR, r9
		sth	  r3, 0(r10)
		lhz	  r6, 2(r10)
		lbz	  r5, 2(r10)
		rotlwi	  r4, r6, 8
		or	  r3, r4, r5
		sth	  r3, 2(r10)

loc_8256C294:				// CODE XREF: sub_82568170+41D0j
		lwz	  r9, 0x42(r11)
		lbz	  r3, 0x42(r11)
		mr	  r5, r9
		rlwinm	  r4, r9, 24,16,23
		insrwi	  r5, r9, 16,0
		extlwi	  r9, r5, 16,8
		or	  r6, r9, r4
		or	  r5, r6, r3
		stw	  r5, 0x42(r11)
		lhz	  r3, 0x46(r11)
		lbz	  r4, 0x46(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x46(r11)
		lhz	  r5, 0x48(r11)
		lbz	  r6, 0x48(r11)
		insrwi	  r6, r5, 16,8
		sth	  r6, 0x48(r11)
		lhz	  r9, 0x4A(r11)
		lbz	  r3, 0x4A(r11)
		insrwi	  r3, r9, 16,8
		sth	  r3, 0x4A(r11)
		lhz	  r4, 0x4C(r11)
		lbz	  r5, 0x4C(r11)
		insrwi	  r5, r4, 16,8
		sth	  r5, 0x4C(r11)
		lhz	  r6, 0x4E(r11)
		lbz	  r9, 0x4E(r11)
		insrwi	  r9, r6, 16,8
		sth	  r9, 0x4E(r11)
		lhz	  r3, 0x50(r11)
		lbz	  r4, 0x50(r11)
		insrwi	  r4, r3, 16,8
		sth	  r4, 0x50(r11)
		lbz	  r6, 0x52(r11)
		lhz	  r5, 0x52(r11)
		insrwi	  r6, r5, 16,8
		clrlwi	  r4, r6, 16
		sth	  r4, 0x52(r11)
		lbz	  r3, 0x54(r11)
		lhz	  r9, 0x54(r11)
		insrwi	  r3, r9, 16,8
		clrlwi	  r6, r3, 16
		sthu	  r6, 0x54(r11)
		bdnz	  loc_8256C294
		addic.	  r7, r7, -1
		addi	  r10, r10, 0x5F0
		bne	  loc_8256C260

loc_8256C350:				// CODE XREF: sub_82568170+40E8j
		addi	  r3, r8, 0x3D48
		bl	  sub_82567D18
		lhz	  r11, 0xA0(r3)
		lbz	  r10, 0xA0(r3)
		rotlwi	  r9, r11, 8
		or	  r8, r9, r10
		sth	  r8, 0xA0(r3)
		lhz	  r6, 0xA2(r3)
		lbz	  r5, 0xA2(r3)
		rotlwi	  r4, r6, 8
		or	  r11, r4, r5
		sth	  r11, 0xA2(r3)
		lwzu	  r11, 0x100(r3)
		mr	  r9, r11
		rlwinm	  r8, r11, 24,16,23
		insrwi	  r9, r11, 16,0
		lbz	  r7, 0(r3)
		extlwi	  r6, r9, 16,8
		or	  r5, r6, r8
		or	  r4, r5, r7
		stw	  r4, 0(r3)
		addi	  r1, r1, 0x100
		//b	  __restgprlr_14
		ld       r14, -0x98(r1)
		ld       r15, -0x90(r1)
		ld       r16, -0x88(r1)
		ld       r17, -0x80(r1)
		ld       r18, -0x78(r1)
		ld       r19, -0x70(r1)
		ld       r20, -0x68(r1)
		ld       r21, -0x60(r1)
		ld       r22, -0x58(r1)
		ld       r23, -0x50(r1)
		ld       r24, -0x48(r1)
		ld       r25, -0x40(r1)
		ld       r26, -0x38(r1)
		ld       r27, -0x30(r1)
		ld       r28, -0x28(r1)
		ld       r29, -0x20(r1)
		ld       r30, -0x18(r1)
		ld       r31, -0x10(r1)
		lwz       r12, -0x8(r1)
		mtspr   LR, r12
		blr
	}
}

void sub_825FBFA0(unsigned int r3) {
	dword_832E05C8[0] = r3;
}

void __declspec(naked) sub_82612620() {
	__asm {
		mfspr	r12, LR
		stw	  r12, -8(r1)
		stwu	  r1, -0x60(r1)
		//lis	  r11, ((unk_834AACE8+0x10000)@h)
		lau   r11, unk_834AACE8
		li	  r5, 0x48
		//addi	  r3, r11, -0x5318 // unk_834AACE8
		lal   r3, r11, unk_834AACE8
		li	  r4, 0
		bl	  memset
		//lis	  r9, ((dword_834A9ED4+0x10000)@h)
		lau   r9, dword_834A9ED8
		li	  r10, 9
		//addi	  r11, r9, -0x612C // dword_834A9ED4
		lal   r11, r9, dword_834A9ED8
		li	  r9, -1
		addi	  r11, r11, -4
		mtspr	CTR, r10

loc_82612658:				// CODE XREF: sub_82612620+3Cj
		//stwu	  r9, ((dword_834A9ED8+0x612C)@l)(r11)
		stwu    r9, 4(r11)
		bdnz	  loc_82612658
		addi	  r1, r1, 0x60
		lwz	  r12, -8(r1)
		mtspr	LR, r12
		blr
	}
}

void __declspec(naked) sub_825C1E38() {
	__asm {
		clrrwi	  r10, r5, 2
		not	  r11, r4
		cmplwi	  cr6, r10, 0
		beq	  cr6, loc_825C1E84
		mtspr	CTR, r10
		//lis	  r10, unk_82001E78@h
		lau   r10, unk_82001E78
		lis	  r8, 0x3FC4 // 0x3FC47CDA
		addi	  r9, r3, -1
		//addi	  r7, r10, unk_82001E78@l
		lal   r7, r10, unk_82001E78
		ori	  r8, r8, 0x7CDA // 0x3FC47CDA

loc_825C1E60:				// CODE XREF: sub_825C1E38+48j
		lbzu	  r5, 1(r9)
		srwi	  r6, r11, 8
		xor	  r4, r5, r11
		clrlwi	  r3, r4, 24
		slwi	  r11, r3, 2
		lwzx	  r10, r11, r7
		xor	  r6, r10, r6
		xor	  r11, r6, r8
		bdnz	  loc_825C1E60

loc_825C1E84:				// CODE XREF: sub_825C1E38+Cj
		not	  r3, r11
		blr
	}
}

void __declspec(naked) sub_825C1F58() {
	__asm {
		mr	  r11, r3
		clrlwi	  r9, r5, 24
		cmpwi	  cr6, r4, 8
		bgt	  cr6, loc_825C1F9C
		cmpwi	  cr6, r4, 0
		ble	  cr6, loc_825C1F94
		mtspr	CTR, r4
		addi	  r11, r11, -1

loc_825C1F78:				// CODE XREF: sub_825C1F58+38j
		lbz	  r10, 1(r11)
		clrlwi	  r8, r9, 24
		xor	  r6, r10, r8
		mr	  r7, r10
		clrlwi	  r5, r6, 24
		stbu	  r5, 1(r11)
		bdnz	  loc_825C1F78

loc_825C1F94:				// CODE XREF: sub_825C1F58+14j
		mr	  r3, r4
		blr
// ---------------------------------------------------------------------------

loc_825C1F9C:				// CODE XREF: sub_825C1F58+Cj
		clrlwi	  r8, r9, 24
		clrlslwi  r7, r9, 24,8
		clrlwi	  r6, r11, 30
		or	  r5, r7, r8
		subfic	  r10, r6, 4
		slwi	  r7, r5, 8
		mr	  r3, r4
		or	  r6, r7, r8
		cmpwi	  cr6, r10, 4
		slwi	  r5, r6, 8
		or	  r8, r5, r8
		beq	  cr6, loc_825C1FF8
		cmpwi	  cr6, r10, 0
		ble	  cr6, loc_825C1FF8
		mtspr	CTR, r10
		subf	  r4, r10, r4

loc_825C1FDC:				// CODE XREF: sub_825C1F58+9Cj
		lbz	  r10, 0(r11)
		clrlwi	  r7, r9, 24
		xor	  r6, r10, r7
		clrlwi	  r5, r6, 24
		stb	  r5, 0(r11)
		addi	  r11, r11, 1
		bdnz	  loc_825C1FDC

loc_825C1FF8:				// CODE XREF: sub_825C1F58+70j
					// sub_825C1F58+78j
		mr	  r10, r4
		cmpwi	  cr6, r4, 4
		blt	  cr6, loc_825C2060
		srwi	  r7, r4, 2
		clrrwi	  r6, r4, 2
		subf	  r10, r6, r4
		mtspr	CTR, r7

loc_825C2014:				// CODE XREF: sub_825C1F58+104j
		lwz	  r7, 0(r11)
		lbz	  r6, 0(r11)
		mr	  r5, r7
		rlwinm	  r4, r7, 24,16,23
		insrwi	  r5, r7, 16,0
		extlwi	  r7, r5, 16,8
		or	  r5, r7, r4
		or	  r4, r5, r6
		xor	  r7, r4, r8
		mr	  r6, r7
		mr	  r5, r7
		inslwi	  r6, r7, 16,16
		insrwi	  r5, r7, 16,0
		extrwi	  r4, r6, 16,8
		extlwi	  r7, r5, 16,8
		or	  r6, r4, r7
		stw	  r6, 0(r11)
		addi	  r11, r11, 4
		bdnz	  loc_825C2014

loc_825C2060:				// CODE XREF: sub_825C1F58+A8j
		cmpwi	  cr6, r10, 0
		blelr	  cr6
		mtspr	CTR, r10
		addi	  r11, r11, -1

loc_825C2070:				// CODE XREF: sub_825C1F58+130j
		lbz	  r10, 1(r11)
		clrlwi	  r8, r9, 24
		xor	  r6, r10, r8
		mr	  r7, r10
		clrlwi	  r5, r6, 24
		stbu	  r5, 1(r11)
		bdnz	  loc_825C2070
		blr
	}
}

void __declspec(naked) sub_825FB170() {
	__asm {
		mfspr	r12, LR
		//bl	  __savegprlr_21
		std       r21, -0x60(r1)
		std       r22, -0x58(r1)
		std       r23, -0x50(r1)
		std       r24, -0x48(r1)
		std       r25, -0x40(r1)
		std       r26, -0x38(r1)
		std       r27, -0x30(r1)
		std       r28, -0x28(r1)
		std       r29, -0x20(r1)
		std       r30, -0x18(r1)
		std       r31, -0x10(r1)
		stw       r12, -0x8(r1)

		stwu	  r1, -0xB0(r1)
		li	  r21, 0
		lis	  r10, 0x5D58 //	0x5D588B65
		//lis	  r11, unk_834B1878@h
		lau   r11, unk_834B1878
		mr	  r22, r21
		mr	  r27, r21
		ori	  r23, r10, 0x8B65 // 0x5D588B65
		li	  r25, 0xFF
		//lis	  r24, dword_832E05C8@h
		lau   r24, dword_832E05C8
		lal   r24, r24, dword_832E05C8
		//addi	  r31, r11, unk_834B1878@l
		lal   r31, r11, unk_834B1878

loc_825FB1A0:				// CODE XREF: sub_825FB170+17Cj
		mr	  r26, r21

loc_825FB1A4:				// CODE XREF: sub_825FB170+F0j
		add	  r11, r22, r26
		li	  r5, 0xCC
		mulli	  r28, r11, 0xCC
		add	  r29, r28, r31
		li	  r4, 0
		mr	  r3, r29
		bl	  memset
		addi	  r11, r31, 0x830
		li	  r5, 0xCC
		add	  r30, r28, r11
		li	  r4, 0
		mr	  r3, r30
		bl	  memset
		//lwz	  r11, dword_832E05C8@l(r24)
		lwz	  r11, 0(r24)
		li	  r5, 0xC8
		mullw	  r11, r11, r23
		addi	  r11, r11, 1
		li	  r4, 0
		rlwinm	  r10, r11, 0,24,30
		//stw	  r11, dword_832E05C8@l(r24)
		stw	  r11, 0(r24)
		mr	  r3, r29
		rlwinm	  r10, r10, 0,28,26
		stbx	  r10, r28, r31
		bl	  sub_825C1E38
		stw	  r3, 0xC8(r29)
		li	  r4, 0xCB
		lbzx	  r5, r28, r31
		addi	  r3, r29, 1
		bl	  sub_825C1F58
		//lwz	  r11, dword_832E05C8@l(r24)
		lwz	  r11, 0(r24)
		li	  r5, 0xC8
		mullw	  r11, r11, r23
		addi	  r11, r11, 1
		li	  r4, 0
		rlwinm	  r9, r11, 0,24,30
		//stw	  r11, dword_832E05C8@l(r24)
		stw	  r11, 0(r24)
		mr	  r3, r30
		rlwinm	  r9, r9, 0,28,26
		stb	  r9, 0(r30)
		bl	  sub_825C1E38
		stw	  r3, 0xC8(r30)
		li	  r4, 0xCB
		lbz	  r5, 0(r30)
		addi	  r3, r30, 1
		bl	  sub_825C1F58
		addi	  r26, r26, 1
		cmpwi	  cr6, r26, 5
		blt	  cr6, loc_825FB1A4
		addi	  r5, r31, 0x814
		addi	  r4, r31, 0x814
		addi	  r3, r5, 2
		addi	  r7, r31, 0x814
		addi	  r6, r31, 0x814
		addi	  r11, r31, 0x7F8
		addi	  r8, r31, 0x814
		stbx	  r25, r27, r4
		addi	  r9, r31, 0x814
		stbx	  r25, r27, r3
		addi	  r10, r31, 0x814
		addi	  r5, r7, 5
		addi	  r6, r6, 4
		addi	  r7, r31, 0x7F8
		addi	  r11, r11, 4
		addi	  r4, r8, 6
		addi	  r3, r9, 8
		stbx	  r21, r27, r5
		addi	  r10, r10, 0xA
		stbx	  r21, r27, r6
		add	  r11, r27, r11
		stbx	  r25, r27, r7
		addi	  r22, r22, 5
		stbx	  r25, r27, r4
		stbx	  r25, r27, r3
		stbx	  r25, r27, r10
		addi	  r27, r27, 0xE
		stb	  r25, -2(r11)
		stb	  r21, 0(r11)
		cmpwi	  cr6, r27, 0x1C
		stb	  r21, 1(r11)
		stb	  r25, 2(r11)
		stb	  r25, 4(r11)
		stb	  r25, 6(r11)
		blt	  cr6, loc_825FB1A0

loc_825FB2F0:				// CODE XREF: sub_825FB170+190j
		clrlwi	  r3, r21, 24
		//bl	  sub_825FA2D8 // really hope I dont need this
		addi	  r21, r21, 1
		cmpwi	  cr6, r21, 5
		blt	  cr6, loc_825FB2F0
		addi	  r1, r1, 0xB0
		//b	  __restgprlr_21
		ld       r21, -0x60(r1)
		ld       r22, -0x58(r1)
		ld       r23, -0x50(r1)
		ld       r24, -0x48(r1)
		ld       r25, -0x40(r1)
		ld       r26, -0x38(r1)
		ld       r27, -0x30(r1)
		ld       r28, -0x28(r1)
		ld       r29, -0x20(r1)
		ld       r30, -0x18(r1)
		ld       r31, -0x10(r1)
		lwz       r12, -0x8(r1)
		mtspr   lr, r12
		blr
	}
}

// I really dont fucking know I dont think this was needed
void InitMGSSecurity() {
	sub_825FBFA0(0x123456);
	// I hope those arent needed
	//sub_82612620();
	//sub_825DB158();
	sub_825FB170();
	//sub_825E8358();
}
