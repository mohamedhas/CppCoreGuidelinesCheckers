// RUN: %check_clang_tidy %s cppcoreguidelines-strongly-typed-interface %t


void func(void *ptr);
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: Function is weakly typed [cppcoreguidelines-strongly-typed-interface]


struct A {
    void foo(void *ptr);
    // CHECK-MESSAGES: :[[@LINE-1]]:10: warning: Function is weakly typed [cppcoreguidelines-strongly-typed-interface]
};

void add(int x, int y);


void *f(int x) ;
// CHECK-MESSAGES: :[[@LINE-1]]:7: warning: Function is weakly typed [cppcoreguidelines-strongly-typed-interface]