#include <iostream>
#include <chrono>
#include <vector>
#include <map>

#include "Key.h"

using namespace std;

int main(int argc, char* argv[])
{
  unsigned char buffer[C+1];     // temporary string buffer
  Key candidate = {{0}};         // a password candidate
  Key encrypted;                 // the encrypted password
  Key candenc;                   // the encrypted password candidate
  Key zero = {{0}};              // the all zero key
  Key T[N];                      // the table T

  map<Key,vector<Key>> halves;

  unsigned char mid[C];
  fill(begin(mid),end(mid),'a');

  if(C % 2 == 0)
  {
      mid[(C/2)-1] = 'b';
  }
  else
  {
      mid[C/2] = 'b';
  }

  Key middle = KEYinit((unsigned char *) mid);

  if (argc != 2)
  {
      cout << "Usage:" << endl << argv[0] << " password < rand8.txt" << endl;

      return 1;
  }

  encrypted = KEYinit((unsigned char *) argv[1]);

  // read in table T
  for (int i{0}; i < N; ++i)
  {
      scanf("%s", buffer);
      T[i] = KEYinit(buffer);
  }

  auto begin = chrono::high_resolution_clock::now();

  // try all possible subsets of T
  do
  {
      candenc = KEYsubsetsum(candidate, T);

      Key tmp;
      tmp = encrypted - candenc;
      halves[tmp].push_back(candidate);

      ++candidate;
  } while (candidate != middle);

  Key interval = middle;
  candidate = {{0}};

  do
  {
      candenc = KEYsubsetsum(candidate, T);

      map<Key,vector<Key>>::iterator it = halves.find(candenc);
      if (it != halves.end())
      {
          for(Key k : halves[candenc])
          {
              cout << candidate + k << endl;
          }
      }

      candidate = candidate + interval;
  } while (candidate != zero);

  auto end = chrono::high_resolution_clock::now();
  cout << "Decryption took "
       << std::chrono::duration_cast<chrono::seconds>(end - begin).count()
       << " seconds." << endl;

  return 0;
}
