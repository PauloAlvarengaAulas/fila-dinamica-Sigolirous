#include <iostream>
using namespace std;
template <class T> class Fila {
  protected:  
    template <class TT> class Celula {
      public:
        Celula<TT> *prox;
        TT valor;
        Celula(TT v) {
          this->valor = v;
          prox = nullptr;
        }
    };
    int tamanho;
    Celula<T> *primeiro;
    Celula<T> *ultimo;
  public:
    Fila() {
      ultimo = primeiro = nullptr;
      tamanho = 0;
    }
    ~Fila() {
      Celula<T> *ax;
      while(primeiro!=nullptr) {
        ax=primeiro;
        primeiro = primeiro->prox;
        delete ax;
      }
    }
    int getTamanho() {
    return tamanho;
    }
    bool inserir(const T &valor) {
      if(this->primeiro == nullptr) {
        this->ultimo = this->primeiro = new Celula<T>(valor);
      } else {
        this->ultimo->prox = new Celula<T>(valor);
        this->ultimo = this->ultimo->prox;
      }
      ++tamanho;
      return true;
    }
    bool excluir(void) {
      if(this->primeiro==nullptr) {
        return false;
      } else {
        Celula<T> *ax;
        ax = primeiro;
        this->primeiro = this->primeiro->prox;
        delete ax;
        --tamanho;
      }
      return true;
    }
    void mostrar() {
      if(this->primeiro== nullptr) {
        cout << "<<nada>>";
      } else {
        cout << this->primeiro->valor;
      }
        cout << endl;
    }
    char getFirst(){
      if(this->primeiro== nullptr) {
        return '0';
      } else {
        return this->primeiro->valor;
      }     
    }
};

int main() {
  Fila<char> music;
  Fila<char> block;
  char ax[10000];
  int okBlocks = 0;
  cin.getline(ax, 10000);
  for(int i = 0; ax[i]; i++){
    music.inserir(ax[i]);
  }
  for(int j = music.getTamanho(); j > 0; j--){
    if(music.getFirst() != '/'){
      block.inserir(music.getFirst());
      music.excluir();
    }
    if(music.getFirst() == '/' && block.getTamanho() != 0){
        music.excluir();
        float time = 0.0;
        for(int k = block.getTamanho(); k > 0; k--){
          block.getFirst() == 'W' ? time +=1 :
          block.getFirst() == 'H' ? time +=0.5 :
          block.getFirst() == 'Q' ? time +=0.25 :
          block.getFirst() == 'E' ? time +=0.125 :
          block.getFirst() == 'S' ? time +=0.0625 :
          block.getFirst() == 'T' ? time +=0.03125 : 
          block.getFirst() == 'T' ? time +=0.015625 :
          time+=0;
          block.excluir();
        }
        if(time == 1){
          okBlocks++;
        }
    }
    if(music.getFirst() == '/' && block.getTamanho() == 0){
      music.excluir();
    }
  }
  cout<<okBlocks<<endl;
  return 0;
}