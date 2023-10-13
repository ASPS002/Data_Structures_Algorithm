#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define speed                    \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);                   \
   cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define setp(x) fixed << setprecision(x)
#define endl "\n"
#define mod 1000000007
#define mod1 998244353
#define ff first
#define ss second
#define MAX 10000005
#define N 2000005
#define K 35
#define INF 10000000
#define all(v) v.begin(), v.end()
#define sbit(a) __builtin_popcount(a)
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ppl;
typedef map<ll, ll> mpll;
typedef map<vector<ll>, ll> mpvl;
ll power(ll x, ll y, ll p)
{
   ll res = 1;

   x = x % p;

   if (x == 0)
      return 0;
   while (y > 0)
   {

      if (y & 1)
         res = (res * x) % p;

      y = y >> 1;
      x = (x * x) % p;
   }

   return res;
}
ll powernm(ll x, ll y)
{
   ll res = 1;

   if (x == 0)
      return 0;
   while (y > 0)
   {

      if (y & 1)
         res = (res * x);

      y = y >> 1;
      x = (x * x);
   }

   return res;
}
ll number_of_strings_char_occur_odd_times(string &s, char c)
{
   ll n = s.length();
   vector<ll> pre(n + 1);
   for (ll i = 1; i <= n; i++)
   {
      pre[i] = (s[i - 1] == c) + pre[i - 1];
   }
   ll even = 1, odd = 0, ans = 0;
   for (ll i = 1; i <= n; i++)
   {
      if (pre[i] % 2)
      {
         odd++;
         ans += even;
      }
      else
      {
         even++;
         ans += odd;
      }
   }
   return ans;
}
ll odd_length_strings(string s)
{
   ll n = s.length();
   ll ans = 0;
   for (ll i = 1; i <= n; i++)
   {
      if (i % 2)
      {
         ans += (n - i + 1);
      }
   }
   return ans;
}
void solve()
{
   ll n;
   cin >> n;
   string s;
   cin >> s;
   char ch = 'a';
   ll ans = 0;
   for (ll i = 0; i < 26; i++)
   {
      ans += number_of_strings_char_occur_odd_times(s, ch);
      ch++;
   }
   cout << ans << " " << odd_length_strings(s) << endl;
   ans -= odd_length_strings(s);
   ld fans = ans;
   cout << ans / 2 << " " << ans << endl;
}
int main()
{
   speed;
   ll kk;
   kk = 1;
   // cin >> kk;
   while (kk--)
   {
      solve();
   }
}