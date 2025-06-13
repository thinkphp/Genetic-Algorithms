
# AIScheduler 

Am dezvoltat AI Scheduler pentru a rezolva problema complexa de planificare a turelor, folosind algoritmi genetici. Aplicatia optimizeaza automat programul unei echipe, respectand constrangeri precum disponibilitatea individuala si necesitatile operationale. Algoritmul evolueaza solutii prin selectie naturala, crossover si mutatie, gasind echilibrul optim între satisfactia angajatilor si eficienta operationala

### **1. Aplicare Practica a Algoritmilor Genetici**
- **Cromozom**: Matrice 7x10 (zile x angajați) cu 1/0 pentru lucru/liber
- **Fitness Function**: Penalizări inteligente pentru încălcarea constrângerilor
- **Operatori Genetici**: Crossover pe angajați, mutație controlată, selecție tournament
- **Elitism**: Păstrează cele mai bune soluții între generații

### **2. Rezolvarea unei Probleme Reale**
- **Planificarea turelor** - problemă comună în HR
- **Constrângeri multiple**: zile minime/maxime, disponibilitate angajați
- **Optimizare sub constrângeri** - demonstrează înțelegerea problemelor complexe

### **3. Arhitectură Bună**
- **Clase separate**: Individual, Population - design orientat pe obiecte
- **Separarea logicii**: UI, algoritm genetic, validări
- **Scalabilitate**: Funcționează cu orice număr de angajați

### **4. UX/UI Profesionist**
- **Design modern** cu gradient-uri și animații
- **Progres în timp real** al algoritmului
- **Statistici detaliate** și vizualizare clară
- **Responsive design** pentru mobile

## **Detalii Tehnice Impresionante:**

**Algoritm Genetic Implementat:**
- Populație de 50 indivizi, 100 generații
- Tournament selection pentru diversitate
- Crossover inteligent pe nivel de angajat
- Mutație adaptivă (15% rate)
- Elitism (10% cei mai buni supraviețuiesc)

**Fitness Function Sofisticată:**
- Penalizare pentru zile cu prea puțini angajați (-50 puncte)
- Penalizare pentru încălcarea preferințelor (-100 puncte)
- Penalizare pentru program prea intensiv (-30 puncte/zi extra)
- Bonus pentru echilibrul optim de lucru
