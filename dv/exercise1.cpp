#include <VExercise1.h>

int main() {
  VExercise1 model;
  model.op=op;
  model.a=a;
  model.b=b;
  model.eval();

  for (int op=0;op<4;op++){
    for (int a=0;a<255;a++){
      for (int b=0;b<255;b++){
           int expected_result;
                switch (op) {
                    case 0: expected_result = a ^ b; break;
                    case 1: expected_result = b<8? a<<b :0; break;
                    case 2: expected_result = (b==0) ? 0 : (a%b); break;
                    case 3: expected_result = ~(a & b); break;
                }
                if (model.out !=expected_result){
                  cout<<"op: "<<op<<"a: "<<a<<"B: "<<b<<endl;
                  return 1;
                }
      }
    }
  }
  return 0; 





}
