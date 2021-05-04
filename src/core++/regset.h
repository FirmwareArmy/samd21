#include <type_traits>

// https://www.javaer101.com/en/article/69393937.html

#define EXPAND(x) x
#define CONCATENATE(x,y) x##y

#define FOR_EACH_ARG_N(\
		_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, \
		_17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32,\
		N, ...) N
#define FOR_EACH_RSEQ_N() \
	32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16,\
	15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
#define FOR_EACH_NARG(...) FOR_EACH_NARG_(__VA_ARGS__, FOR_EACH_RSEQ_N())
#define FOR_EACH_NARG_(...) EXPAND(FOR_EACH_ARG_N(__VA_ARGS__))

#define FOR_EACH_1(F, x) F(x)
#define FOR_EACH_2(F, x, ...) F(x) EXPAND(FOR_EACH_1(F, __VA_ARGS__))
#define FOR_EACH_3(F, x, ...) F(x) EXPAND(FOR_EACH_2(F, __VA_ARGS__))
#define FOR_EACH_4(F, x, ...) F(x) EXPAND(FOR_EACH_3(F, __VA_ARGS__))
#define FOR_EACH_5(F, x, ...) F(x) EXPAND(FOR_EACH_4(F, __VA_ARGS__))
#define FOR_EACH_6(F, x, ...) F(x) EXPAND(FOR_EACH_5(F, __VA_ARGS__))
#define FOR_EACH_7(F, x, ...) F(x) EXPAND(FOR_EACH_6(F, __VA_ARGS__))
#define FOR_EACH_8(F, x, ...) F(x) EXPAND(FOR_EACH_7(F, __VA_ARGS__))
#define FOR_EACH_9(F, x, ...) F(x) EXPAND(FOR_EACH_8(F, __VA_ARGS__))
#define FOR_EACH_10(F, x, ...) F(x) EXPAND(FOR_EACH_9(F, __VA_ARGS__))
#define FOR_EACH_11(F, x, ...) F(x) EXPAND(FOR_EACH_10(F, __VA_ARGS__))
#define FOR_EACH_12(F, x, ...) F(x) EXPAND(FOR_EACH_11(F, __VA_ARGS__))
#define FOR_EACH_13(F, x, ...) F(x) EXPAND(FOR_EACH_12(F, __VA_ARGS__))
#define FOR_EACH_14(F, x, ...) F(x) EXPAND(FOR_EACH_13(F, __VA_ARGS__))
#define FOR_EACH_15(F, x, ...) F(x) EXPAND(FOR_EACH_14(F, __VA_ARGS__))
#define FOR_EACH_16(F, x, ...) F(x) EXPAND(FOR_EACH_15(F, __VA_ARGS__))
#define FOR_EACH_17(F, x, ...) F(x) EXPAND(FOR_EACH_16(F, __VA_ARGS__))
#define FOR_EACH_18(F, x, ...) F(x) EXPAND(FOR_EACH_17(F, __VA_ARGS__))
#define FOR_EACH_19(F, x, ...) F(x) EXPAND(FOR_EACH_18(F, __VA_ARGS__))
#define FOR_EACH_20(F, x, ...) F(x) EXPAND(FOR_EACH_19(F, __VA_ARGS__))
#define FOR_EACH_21(F, x, ...) F(x) EXPAND(FOR_EACH_20(F, __VA_ARGS__))
#define FOR_EACH_22(F, x, ...) F(x) EXPAND(FOR_EACH_21(F, __VA_ARGS__))
#define FOR_EACH_23(F, x, ...) F(x) EXPAND(FOR_EACH_22(F, __VA_ARGS__))
#define FOR_EACH_24(F, x, ...) F(x) EXPAND(FOR_EACH_23(F, __VA_ARGS__))
#define FOR_EACH_25(F, x, ...) F(x) EXPAND(FOR_EACH_24(F, __VA_ARGS__))
#define FOR_EACH_26(F, x, ...) F(x) EXPAND(FOR_EACH_25(F, __VA_ARGS__))
#define FOR_EACH_27(F, x, ...) F(x) EXPAND(FOR_EACH_26(F, __VA_ARGS__))
#define FOR_EACH_28(F, x, ...) F(x) EXPAND(FOR_EACH_27(F, __VA_ARGS__))
#define FOR_EACH_29(F, x, ...) F(x) EXPAND(FOR_EACH_28(F, __VA_ARGS__))
#define FOR_EACH_30(F, x, ...) F(x) EXPAND(FOR_EACH_29(F, __VA_ARGS__))
#define FOR_EACH_31(F, x, ...) F(x) EXPAND(FOR_EACH_30(F, __VA_ARGS__))
#define FOR_EACH_32(F, x, ...) F(x) EXPAND(FOR_EACH_31(F, __VA_ARGS__))


#define FOR_EACH2_ARG_N(\
		_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, \
		_17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32,\
		_33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, \
		_49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, \
		N, ...) N
#define FOR_EACH2_RSEQ_N() \
	64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, \
    48,	47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, \
    32, 31,	30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, \
    16,	15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
#define FOR_EACH2_NARG(...) FOR_EACH2_NARG_(__VA_ARGS__, FOR_EACH2_RSEQ_N())
#define FOR_EACH2_NARG_(...) EXPAND(FOR_EACH2_ARG_N(__VA_ARGS__))


#define FOR_EACH2_2(F, x, y) F(x, y)
#define FOR_EACH2_4(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_2(F, __VA_ARGS__))
#define FOR_EACH2_6(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_4(F, __VA_ARGS__))
#define FOR_EACH2_8(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_6(F, __VA_ARGS__))
#define FOR_EACH2_10(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_8(F, __VA_ARGS__))
#define FOR_EACH2_12(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_10(F, __VA_ARGS__))
#define FOR_EACH2_14(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_12(F, __VA_ARGS__))
#define FOR_EACH2_16(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_14(F, __VA_ARGS__))
#define FOR_EACH2_18(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_16(F, __VA_ARGS__))
#define FOR_EACH2_20(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_18(F, __VA_ARGS__))
#define FOR_EACH2_22(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_20(F, __VA_ARGS__))
#define FOR_EACH2_24(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_22(F, __VA_ARGS__))
#define FOR_EACH2_26(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_24(F, __VA_ARGS__))
#define FOR_EACH2_28(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_26(F, __VA_ARGS__))
#define FOR_EACH2_30(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_28(F, __VA_ARGS__))
#define FOR_EACH2_32(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_30(F, __VA_ARGS__))
#define FOR_EACH2_34(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_32(F, __VA_ARGS__))
#define FOR_EACH2_36(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_34(F, __VA_ARGS__))
#define FOR_EACH2_38(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_36(F, __VA_ARGS__))
#define FOR_EACH2_40(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_38(F, __VA_ARGS__))
#define FOR_EACH2_42(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_40(F, __VA_ARGS__))
#define FOR_EACH2_44(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_42(F, __VA_ARGS__))
#define FOR_EACH2_46(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_44(F, __VA_ARGS__))
#define FOR_EACH2_48(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_46(F, __VA_ARGS__))
#define FOR_EACH2_50(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_48(F, __VA_ARGS__))
#define FOR_EACH2_52(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_50(F, __VA_ARGS__))
#define FOR_EACH2_54(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_52(F, __VA_ARGS__))
#define FOR_EACH2_56(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_54(F, __VA_ARGS__))
#define FOR_EACH2_58(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_56(F, __VA_ARGS__))
#define FOR_EACH2_60(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_58(F, __VA_ARGS__))
#define FOR_EACH2_62(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_60(F, __VA_ARGS__))
#define FOR_EACH2_64(F, x, y, ...) F(x, y) EXPAND(FOR_EACH2_62(F, __VA_ARGS__))

#define FOR_EACH_(N, F, ...) EXPAND(CONCATENATE(FOR_EACH_, N)(F, __VA_ARGS__))
#define FOR_EACH(F, ...) FOR_EACH_(FOR_EACH_NARG(__VA_ARGS__), F, __VA_ARGS__)

#define FOR_EACH2_(N, F, ...) EXPAND(CONCATENATE(FOR_EACH2_, N)(F, __VA_ARGS__))
#define FOR_EACH2(F, ...) FOR_EACH2_(FOR_EACH2_NARG(__VA_ARGS__), F, __VA_ARGS__)

#define _regMaskOP(Field) .Field = 0xFFFFFFFFu,
#define _regMaskValOP(Field, Value) .Field = 0xFFFFFFFFu,
#define _regSetOP(Field) .Field = 0xFFFFFFFFu,
#define _regSetValOP(Field, Value) .Field = Value,
#define _regClrOP(Field) .Field = 0,

/**
 * Create a bitmask from a register
 * mask = regMask(reg, FIELD1, FIELD2)
 */
#define regMask(Register, ...) std::remove_volatile<decltype(Register)>::type{{ FOR_EACH(_regMaskOP, __VA_ARGS__) }}.reg

/**
 * Set fields, fields are filed with 1, other fields are set to 0
 * regSet(reg, FIELD1, FIELD2)
 */
#define regClrSet(Register,...) Register.reg = std::remove_volatile<decltype(Register)>::type{{ FOR_EACH(_regSetOP, __VA_ARGS__) }}.reg

/**
 * Set fields to specified value, all other bits are set to 0
 * regSet(reg, FIELD1, 0x1, FIELD2, 0b11101)
 */
#define regClrSetVal(Register,...) Register.reg = std::remove_volatile<decltype(Register)>::type{{ FOR_EACH2(_regSetValOP, __VA_ARGS__) }}.reg

/**
 * Set fields to specified value, all other bits remains untouched
 * regSet(reg, FIELD1, FIELD2)
 */
#define regSet(Register,...) Register.reg = Register.reg & ~std::remove_volatile<decltype(Register)>::type{{ FOR_EACH(_regMaskOP, __VA_ARGS__) }}.reg | std::remove_volatile<decltype(Register)>::type{{ FOR_EACH(_regSetOP, __VA_ARGS__) }}.reg

/**
 * Set fields to specified value, all other bits remains untouched
 * regSet(reg, FIELD1, 0x1, FIELD2, 0b11101)
 */
#define regSetVal(Register,...) Register.reg = Register.reg & ~std::remove_volatile<decltype(Register)>::type{{ FOR_EACH2(_regMaskValOP, __VA_ARGS__) }}.reg | std::remove_volatile<decltype(Register)>::type{{ FOR_EACH2(_regSetValOP, __VA_ARGS__) }}.reg

/**
 * Set fields to 0, all other bits remains untouched
 * regSet(reg, FIELD1, FIELD2)
 */
#define regClr(Register,...) Register.reg = Register.reg & ~std::remove_volatile<decltype(Register)>::type{{ FOR_EACH(_regMaskOP, __VA_ARGS__) }}.reg | std::remove_volatile<decltype(Register)>::type{{ FOR_EACH(_regClrOP, __VA_ARGS__) }}.reg

/**
 * Toggle fields, all other bits remains untouched
 * regSet(reg, FIELD1, FIELD2)
 */
#define regTgl(Register,...) Register.reg = Register.reg ^ std::remove_volatile<decltype(Register)>::type{{ FOR_EACH(_regSetOP, __VA_ARGS__) }}.reg
