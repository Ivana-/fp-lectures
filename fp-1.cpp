//////////////////////////////////////////////////////////////////////////////////////////////////
// Task - find sum on first n elements in array
//////////////////////////////////////////////////////////////////////////////////////////////////

// compiler options
// -Wall -std=c++14 -O2 -o a.out source_file.cpp
// -Wall -std=c++14   -o a.out source_file.cpp

#include <iostream>

typedef unsigned long long int ull;

const int N = 1E8;
int m[N];



// imperative mutable algorythm
ull f(int n) {
    ull s = 0;
    for (int i=0; i<=n; i++) s += m[i];
    return s;
}



// non-tail recursion immutable algorythm
ull g(int n) { return (n<0) ? 0 : m[n] + g(n-1); }



// tail recursion immutable algorythm
ull h(int n, ull s) { return (n<0) ? s : h(n-1, m[n] + s); }



// binary-split recursion immutable algorythm
ull d(int b, int e) {
    int c = (b + e)/2;
    return (b==e) ? m[b] : d(b, c) + d(c+1, e);
}



int main() {
    for (int i=0; i<N; i++) m[i] = i;

    int n = 1E1; //1E7;
    std::cout << f(n) << "\n";
    std::cout << g(n) << "\n";
    std::cout << h(n, 0) << "\n";
    std::cout << d(0, n) << "\n";
}



// Max recursion depth calculation. Can you do it in functional way? :)
/*
int max_l = 0;

ull d(int b, int e, int l) {
    int c = (b + e)/2;
    int nxt_l = l + 1;
    max_l = std::max(max_l, nxt_l);

    return (b==e) ? m[b] : d(b, c, nxt_l) + d(c+1, e, nxt_l);
}

    max_l = 0;
    std::cout << d(0, n, 0) << "\n";
    std::cout << max_l << "\n";
*/


// Max recursion depth calculation - functional way
/*
typedef std::pair <ull, int> ull_int;

ull_int dd(int b, int e, int l) {
    int c = (b + e)/2;
    int nxt_l = l + 1;

    if (b==e)
        return std::make_pair(m[b], nxt_l);
    else {
        ull_int r1 = dd(b, c, nxt_l);
        ull_int r2 = dd(c+1, e, nxt_l);
        return std::make_pair(r1.first + r2.first, std::max(r1.second, r2.second));
    }
}

    ull_int r = dd(0, n, 0);
    std::cout << r.first << "\n";
    std::cout << r.second << "\n";
*/


// Haskel code
/*
m i = i

h n s = if (n<0) then s else h (n-1) (m n + s)

main = print $ h 10 0
*/

