#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>

/**
 * @brief ¼ÆËã2^1000,²¢Êä³ö
 */

class BigInt
{
public:
  explicit BigInt(std::string_view val):_val(val){}

  explicit BigInt(const long long int val):_val(std::to_string(val)){}

  BigInt& operator*=(const int num)
  {
    int pre = 0;
    for (auto i = _val.rbegin();i != _val.rend();++i) {
      const int data = ((*i - '0')*num) + pre;
      pre = data / 10;
      *i = '0' + data%10;
    }
    if (pre > 0) {
      _val.insert(0,1,'0' + pre);
    }
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os,const BigInt& val) {
    os<<val._val;
    return os;
  }

private:
  std::string _val;
};

int main()
{
  BigInt big(2);

  for (int i=1;i<1000;++i) {
    big *= 2;
  }

  std::cout<<big<<std::endl;

  return 0;
}