#include <vector>
#include <iostream>
#include <chrono>
















std::vector<int> primeSet;                            
int upperLimit;


void primeCheck(int number);
void printPrimes();
int searchPrimeSet(int prime);
void indexingNth();







class Timer {
private:

  using Clock = std::chrono::steady_clock;
  using Second = std::chrono::duration< double, std::ratio<1> >;

  std::chrono::time_point<Clock> m_beg { Clock::now() };

public:
  void reset() {
    m_beg = Clock::now();
  }

  double elapsed() const {
    return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
  }
};



int main() {


  std::cout << "How many prime numbers would you like?  ";
  std::cin >> upperLimit;
  std::cout << '\n' << "Generating primes..." << '\n';

  Timer generationTimer;


  for (int i = 2; primeSet.size() < upperLimit; ++i) {
    primeCheck(i);
  }

  double generationTime = generationTimer.elapsed();
  Timer printTimer;


  printPrimes();

  double printTime = printTimer.elapsed();
  std::cout << '\n' << "Generation Time: " << generationTime << "s" << '\n';
  std::cout << "Print Time: " << printTime << "s" << '\n';

  indexingNth();

}





void primeCheck(int number) {

  bool isPrime { true };



  for (int prime : primeSet) {
    if (number % prime == 0) { isPrime = false; }
  };


  if (isPrime) { primeSet.push_back(number); }
  return;

}


void printPrimes() {


  std::cout << primeSet[0];


  for (int prime : primeSet) {
    if (prime == 2) { continue; }
    std::cout << ", " << prime;
  }
  std::cout << '\n';

}


int searchPrimeSet(int prime) {

  int index { -1 };


  for (int i = 0; i < upperLimit; ++i) {
    if ( prime == primeSet[i] ) {

      index = i + 1;
    }
  }


  if (index == -1) { throw "Invalid input, not in generated prime set"; }

  return index;

}

void indexingNth() {


  int nthPrime;
  std::cout << '\n' << "Which prime number would you like to index?  ";
  std::cin >> nthPrime;


  try {

    Timer searchTimer;

    int n { searchPrimeSet(nthPrime) };

    double searchTime { searchTimer.elapsed() };
    std::cout << "Search Time: " << searchTime << "s" << "\n\n";

    std::cout << nthPrime << " is " << n << "th in the set of primes." << '\n';

  } catch (const char* ) {

    std::cout << "Invalid input, not in generated prime set" << '\n';
    indexingNth();

  }

}