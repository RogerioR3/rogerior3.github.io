public class Main {
    public static void main(String[] args) {
        Originator originator = new Originator();
        Caretaker caretaker = new Caretaker();
        
        // Salva o estado inicial
        originator.setState("State1");
        caretaker.addMemento(originator.save());
        
        // Muda o estado do Originator
        originator.setState("State2");
        caretaker.addMemento(originator.save());
        
        // Muda novamente o estado do Originator
        originator.setState("State3");
        
        // Restaura o estado para o primeiro estado salvo
        originator.restore(caretaker.getMemento(0));
    }
}

/*
Explicação
    Memento: Esta classe armazena o estado do Originator. Ela possui um construtor para definir o estado 
             e um método getState() para recuperá-lo.
    
    Originator: Esta classe mantém o estado que precisa ser salvo e restaurado. Ela possui métodos para 
                definir e obter o estado, além de criar e restaurar Mementos.
    
    Caretaker: Esta classe gerencia os Mementos. Ela armazena uma lista de Mementos e fornece métodos para 
               adicionar e recuperar Mementos da lista.
    
    Main: A classe principal demonstra o uso do padrão Memento. Ela cria um Originator e um Caretaker, 
          altera o estado do Originator, salva estados em Mementos e restaura um estado anterior.

Este exemplo em Java mostra como o padrão Memento pode ser implementado para salvar e restaurar o estado de 
um objeto, mantendo o encapsulamento e facilitando a implementação de funcionalidades como desfazer e refazer.
*/