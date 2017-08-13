#ifndef __QUICKCHECK_H__
#define __QUICKCHECK_H__

#include <vector>
#include <iostream>

template <typename IN, typename OUT, typename C>
class QuickCheck {
private:
  std::vector<IN> input;
  std::vector<OUT> output;
protected:
  bool verify(OUT std, OUT ans){
    return std == ans;
  }
public:
  QuickCheck () {};
  QuickCheck(const std::vector<IN> &in, const std::vector<OUT> & out){
    setInput(in);
    setOutput(out);
  }
  void setInput(const std::vector<IN> & in){
    input.clear();
    input.insert(input.begin(),
                 in.begin(),
                 in.end());
  }
  void setOutput(const std::vector<OUT> & out){
    output.clear();
    output.insert(output.begin(),
                  out.begin(),
                  out.end());
  }
  void runTests(){
    using namespace std;
    if (input.size() != output.size()){
      cout << "QuickCheck Config Error: Have " <<
        input.size() << " standard input, while have " <<
        output.size() << " standard output!" << endl;
      return;
    }

    int failed = 0;
    for (int i = 0; i < input.size(); i++){
      C object;
      OUT std = output[i];
      OUT ans = object.run(input[i]);
      if (!verify(std, ans)){
        failed ++;
        cout << "Failed test " << i+1 << ".\n  Input: \""<< input[i] << "\".\n" <<
          "  Expected \"" << std <<  "\"\n  Got \"" << ans << "\"" << endl;
      }
    }
    if (failed == 0){
      cout << "OK. Passed all " << input.size() << " test cases." << endl;
    } else {
      cout << "Failed! Passed " << input.size() - failed << " test cases, failed " <<
        failed << " test cases!" << endl;
    }
  }
};

#endif
