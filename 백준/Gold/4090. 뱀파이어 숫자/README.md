# [Gold V] 뱀파이어 숫자 - 4090 

[문제 링크](https://www.acmicpc.net/problem/4090) 

### 성능 요약

메모리: 2024 KB, 시간: 2244 ms

### 분류

이분 탐색(binary_search), 브루트포스 알고리즘(bruteforcing), 구현(implementation), 런타임 전의 전처리(precomputation)

### 문제 설명

<p>
	1827은 흥미로운 수이다. 그 이유는 1827=21*87이고, 좌변과 우변에 나온 숫자가 모두 같기 때문이다. 또, 136948도 비슷한 성질을 가지고 있다. 136948=146*938</p>

<p>
	위에서 설명한 숫자를 뱀파이어 숫자라고 한다. 즉, v가 뱀파이어 숫자가 되려면, 두 수 a와 b의 곱(v=a*b)으로 나타낼 수 있어야 하고, a와 b에 등장하는 숫자와 v와 같아야 한다. 또, a와 b의 자리수도 같아야 한다. v, a, b는 0으로 시작할 수 없다.</p>

<p>
	a와 b의 길이가 같아야 하기 때문에, v는 짝수 자리이어야 하지만, 이 문제에서는 a와 b의 길이가 다른 것도 뱀파이어 숫자라고 한다.</p>

<p>
	아래는 뱀파이어 숫자의 예이다.</p>

<p>
	126 = 6*21</p>
<p>
	10251 = 51*201</p>
<p>
	702189 = 9*78021</p>
<p>
	29632 = 32*926</p>

<p>
	숫자 X가 주어졌을 때, X보다 크거나 같은 뱀파이어 숫자 중 가장 작은 수를 찾는 프로그램을 작성하시오.</p>

### 입력 

 <p>
	입력은 여러개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 정수 X(10 ≤ X ≤ 1,000,000)를 포함하는 한 줄로 이루어져 있다. 입력은 0이 있는 줄에서 끝난다.</p>

### 출력 

 <p>
	각각의 테스트 케이스에 대해서, X보다 크거나 같은 뱀파이어 숫자 중 가장 작은 작은 수를 출력한다.</p>

