#pragma once

typedef int ret_val_t;

/* use a type "ret_val" for function call return values to indicate
 * success or failure of the function call */
#define RET_SUCCESS        (0)   // Successful function call
#define RET_UNIMPLEMENTED  (-1)  // Unimplemented function call
#define RET_FAIL           (-2)  // Generic failure
