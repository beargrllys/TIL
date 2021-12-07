## Algorithm Chap2

### 키워드

> - Sequential Search
>
> - Binary Search
> - Fibonacci Sequence [Recursive, Iterative]
> - Every-case Analysis / Worst-case Analysis / Average-case Analysis / Best-case Analysis
> - Efficiency analysis / Correctioness analysis
> - Growth Function(Order Function)
> - Big O / Big Ω / Big θ
> - Properties of Oder Function

### 예제

#### Example 1.1) The following is an example of a problem: Sort a list S of n numbers in nondecreasing order. The answer is the numbers in sorted sequence.

![image-20211205182440128](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211205182440128.png)

> Parameter : variables that are not assigned specific values in the statement of the problem.
>
> Instance : Each specific assignment of values to the parameters
>
> solution : the answer to the question asked by the problem in that instance.
>
> algorithm : specify a general step-by-step procedure for producing the solution to each instance.

---

#### Example 1.3) An instance of the problem in Example 1.1 is

![image-20211205182756023](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211205182756023.png)

#### What is solution of this instance?

##### S = [5,7,8,10,11,13]

---

#### Example 1.4) An instance of the problem in Example 1.2 is 

![image-20211205183428300](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211205183428300.png)

#### What is the solution?

##### "yes, x is in S."

---

#### Algorithm1 ) Sequential Search

``` c++
void seqsearch(int n, int S[], int x, int* location){

    while(*location <= n && S[*location] != x){
        //cout << *location << endl;
        *location += 1;
    }

    if(*location > n)
        *location = 0;
}
```

---

#### Algorithm2 ) Binary Search

``` C++
void binarySearch(int n, int S[], int x, int* location){
    int low, high, mid;
    low = 1; high = n;
    *location  = 0;

    while(low <= high && *location == 0){
        mid = (low+high)/2;
        if(x == S[mid])
            *location = mid;
        else if(x < S[mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }
}``` 
```

> Worst : log2N - 1

---

#### Algorithm3) Fibonacci Sequence(recursive)

```c++
int fib(int n){
    if(n <= 1)
        return n;
    else
        return fib(n-1) + fib(n-2);
}
```

> recursive하게 계산할 경우 기하급수적으로 계산량이 늘어남 

![image-20211207172159005](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211207172159005.png)

> Recursive Pibonacci Version 계산량 산정 이론

#### Algorithm 4) Fibonacci Sequence(Iterative version)

```c++

int fib2( int n){
    int i;
    int f[10];

    f[0] = 0;
    if(n > 0){
        f[1] = 1;
        for( i=2; i<n; i++)
            f[i] = f[i-1] + f[i-2];
    }
    return f[n-1];
}
```

> T(n) = n + 1

---

- Every-case Analysis : 입력의 값과는 상관없이 반드시 연산되어야 하는 연산량의 결과값은 일정한 척도
- Average-Case analysis: 모든 입력에 대한 단위연산 수행의 기대치
- Worst-Case analysis : 최악의 경우 분서
- Best-Case analysis : 최선의 경우 분석

---

Efficiency analysis VS Correctioness analysis

---

#### 1 ) Write an algorithm that finds the largest number in a list (an array) of n numbers.
```C++
void large_Num(const keytype S[],int n, int& max){
	max = -INF;
    for(int i = 0; i < n; i++){
        if(max < S[i])
            max = S[i];
    }
}
```

---

#### 2) Write an algorithm that finds the m smallest numbers in a list of n numbers.

```C++
void large_Num(const keytype S[],int n, int& min){
	min = INF;
    for(int i = 0; i < n; i++){
        if(min > S[i])
            min = S[i];
    }
}
```

---

#### 3) Write an algorithm that prints out all the subsets of three elements of a set of n elements. The elements of this set are stored in a list that is the input to the algorithm.

```C++
void subest(const keytype S[], int n){
    int list[][3], index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                list[index][i] = S[i]
                list[index][j] = S[j]
                list[index][k] = S[k]
                index++;
                subset(list[index]);
            }
        }
    }            
}
```

