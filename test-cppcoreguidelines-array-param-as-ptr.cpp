// RUN: %check_clang_tidy %s cppcoreguidelines-array-param-as-ptr %t




void foo(int *x) {
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: function  is insufficiently awesome [cppcoreguidelines-array-param-as-ptr]    
    x[2] = 3 ;    
}

void fun(int s[2] ) {
    s[0] = 2 ;
    
}