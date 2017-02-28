#import <iostream>

using namespace std;
string UrlDecode(const string& szToDecode)
{
  string result;
  int hex = 0;
  for (size_t i = 0; i < szToDecode.length(); ++i)
    {
      switch (szToDecode[i])
        {
          //        case '+':
          //这里不需要+号编程空格
          //result += ' ';
          //          break;
        case '%':
          if (isxdigit(szToDecode[i + 1]) && isxdigit(szToDecode[i + 2]))
            {
              std::string hexStr = szToDecode.substr(i + 1, 2);
              hex = strtol(hexStr.c_str(), 0, 16);
              //字母和数字[0-9a-zA-Z]、一些特殊符号[$-_.+!*'(),] 、以及某些保留字[$&+,/:;=?@]
              //可以不经过编码直接用于URL
              if (!((hex >= 48 && hex <= 57) || //0-9
                    (hex >=97 && hex <= 122) ||   //a-z
                    (hex >=65 && hex <= 90) ||    //A-Z
                    //一些特殊符号及保留字[$-_.+!*'(),]  [$&+,/:;=?@]
                    hex == 0x21 || hex == 0x24 || hex == 0x26 || hex == 0x27 || hex == 0x28 || hex == 0x29
                    || hex == 0x2a || hex == 0x2b|| hex == 0x2c || hex == 0x2d || hex == 0x2e || hex == 0x2f
                    || hex == 0x3A || hex == 0x3B|| hex == 0x3D || hex == 0x3f || hex == 0x40 || hex == 0x5f
                    ))
                {
                  if (hex == 0x2b)
                  result += char(hex);
                  i += 2;
                }
              else {
                result += '%';
              }

            }else {
            result += '%';
          }
          break;
        default:
          result += szToDecode[i];
          break;
        }
    }
  return result;
}

int main( int argc, char *argv[]){
  std::cout << UrlDecode(argv[1]) << std::endl;
}
