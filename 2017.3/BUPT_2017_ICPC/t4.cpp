#include <iostream>
#include <set>

using namespace std;

const int LEN = 1000001;

int primes[80001];
long long sums[80001];
set<long long> st;
bool flag[LEN];

int generatePrimes(){
  st.clear();
  int index = 0;
  for (int i = 2; i < LEN; i++){
    if (!flag[i])
      primes[index++] = i;
    for (int j = 0; (j < index) && (i * primes[j] < LEN); j++){
      flag[i * primes[j]] = true;
      if (i % primes[j] == 0)
        break;
    }
  }
  st.insert(2);
  sums[0] = 2;
  for (int i = 1; i < index; i++){
    sums[i] = (sums[i-1] + primes[i]);
    st.insert(sums[i]);
  }
  return index;
}

int upperBound(int n, int r){
  int l = 0;
  while (l < r){
    int mid = (l + r) >> 1;
    if (primes[mid] < n){
      l = mid + 1;
    } else if (primes[mid] > n){
      r = mid - 1;
    } else {
      return mid;
    }
  }
  return r;
}

int lowerBound(int n, int r){
  int l = 0;
  while (l < r){
    int mid = (l + r) >> 1;
    if (sums[mid] < n){
      l = mid + 1;
    } else if (sums[mid] > n){
      r = mid - 1;
    } else {
      return mid;
    }
  }
  return l;
}

int main(){
  int p = generatePrimes();
  int n;
  while (cin >> n){
    int count = 0;
    int left = lowerBound(n, p), right = upperBound(n, p);
    while (right >= left){
      if (sums[right] == n || st.find(sums[right] - n) != st.end())
        count++;
      right--;
    }
    cout << count << endl;
  }
  return 0;
}



/*
2 3 5   7   11   13   17
2 5 10  17  28   41   58
 */
