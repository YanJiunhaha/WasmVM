#include <skypat/skypat.h>

#define _Bool bool
extern "C" {
#include <dataTypes/Value.h>
#include <core/Runtime.h>
}
#undef _Bool

SKYPAT_F(Runtime_f32_neg, regular)
{
    // prepare
    Stack stack = new_Stack();
    Value *val1 = new_f32Value(5), *val2 = new_f32Value(-3);
    push_Value(stack, val1);
    push_Value(stack, val2);

    // run negative
    runtime_f32_neg(stack);

    // check
    Value *check1 = NULL;
    pop_Value(stack,&check1);
    EXPECT_EQ(check1->value.f32, 3);

    // run positive
    runtime_f32_neg(stack);

    // check
    Value *check2 = NULL;
    pop_Value(stack,&check2);
    EXPECT_EQ(check2->value.f32, -5);

    // clean
    free_Value(check1);
    free_Value(check2);
    free_Stack(stack);
}
