############################ Problema Numarare ################################
    Am utilizat o abordare bazata pe programare dinamica pentru a determina
numarul de cai de la nodul 1 la nodul N care sunt comune in ambele grafuri.
    Citesc doua grafuri, fiecare cu N noduri si M muchii. Initial, se 
construieste primul graf si se stocheaza muchiile intr-un vector de seturi.
Apoi, se citeste al doilea graf si se verifica daca muchia citita apare si in
primul graf. Daca exista, actualizam numarul de lanturi elementare catre nodul de 
destinatie y, adaugand numarul de cai catre nodul de origine x modulo MOD. Aceasta
abordare ne permite sa determinam numarul de cai de la nodul 1 la nodul N care sunt 
comune in ambele grafuri.
    Complexitate:
Construirea primului graf are o complexitate de O(MlogN) (facem M citiri + insert intr-un set).
Citirea celui de-al doilea graf si verificarea existentei muchiilor in primul graf
are, de asemenea, o complexitate de O(MlogN) (facem iar M citiri + find intr-un set).
Actualizarea vectorului pathCt are o complexitate de O(1) pentru fiecare muchie care
este comuna in ambele grafuri.
Astfel, complexitatea totala de timp este O(MlogN).

############################# Problema Trenuri ################################
    Aceasta problema implica determinarea numarului maxim de orase care pot fi 
vizitate de la un oras de start la un oras de destinatie, folosind rutele 
directe intre orase.
    Pentru a rezolva aceasta problema, se utilizeaza o abordare de cautare in 
adancime (DFS) si programare dinamica.
    Functia dfs este functia de cautare in adancime. Aceasta primeste orasul 
curent, orasul de destinatie, lista de adiacenta a oraselor, un map care 
stocheaza numarul maxim de orase care pot fi vizitate de la fiecare oras si un
map care stocheaza orasele vizitate.
    In functia main, programul citeste orasul de start si orasul de destinatie,
numarul de rute directe si rutele directe intre orase. Apoi, apeleaza functia 
dfs pentru a gasi numarul maxim de orase care pot fi vizitate de la orasul de 
start la orasul de destinatie si scrie acest numar in fisierul de iesire.
    Complexitatate:
        Citirea datelor: O(M)
        Construirea listei de adiacenta: O(M)
        Calculul cailor (DFS): O(N + M)
        Complexitatea totala a programului este: O(M)+O(M)+O(N+M)=O(N+M)

############################# Problema Drumuri ################################
    Pentru a rezolva aceasta problema, am utilizat o abordare bazata pe algoritmul 
Dijkstra pentru a gasi distantele minime de la nodurile x, y si z la toate 
celelalte noduri din graf. Apoi, se parcurg toate muchiile si se alege submultimea 
de muchii care minimizeaza suma costurilor si respecta conditiile problemei.
    Functia dijkstra primeste nodul sursa, un index care indica pentru care nod 
sursa se calculeaza distantele, lista de adiacenta a grafului, matricea de distante 
si numarul de noduri. Functia initializeaza distantele de la nodul sursa la toate 
celelalte noduri cu infinit si apoi parcurge graful, actualizand distantele.
    In functia main, programul citeste numarul de noduri si de muchii, muchiile 
grafului si nodurile x, y si z. Apoi, apeleaza functia dijkstra pentru fiecare 
dintre cele trei noduri si calculeaza suma minima a costurilor muchiilor care 
respecta conditiile problemei.
    Complexitate:
        Complexitate Totala: O((N+M)*logN)

################################### Scandal ###################################
    Problema "Scandal" se refera la organizarea unei liste de participanti la o
petrecere, in conformitate cu anumite norme stabilite intre prieteni. Acesti 
prieteni sunt reprezentati printr-un grup de N persoane si M reguli, definite 
prin triplete (x, y, c). Fiecare regula are implicatii diferite, stabilind 
conditiile in care prietenii pot sau nu sa fie prezenti la eveniment. Obiectivul
este de a compila o lista de invitati astfel incat nicio regula stabilita nu 
este incalcata.

Reguli:
    - c = 0: Cel putin unul dintre prietenii x sau y trebuie sa participe la petrecere.
    - c = 1: Daca x nu participa, nici y nu va participa.
    - c = 2: Daca y nu participa, nici x nu va participa.
    - c = 3: Cel putin unul dintre x si y nu participa la petrecere.

    Fiecare regula este convertita in muchii directionate intr-un graf si in 
graful sau transpus.
    Identificarea componentelor tare conexe: Utilizam algoritmul  Kosaraju-Sharir
pentru a gasi componentele tare conexe, stabilind astfel relatiile logice intre
participantii la petrecere.
    Verificare si construirea solutiei: Examinam componentele pentru a detecta 
orice incoerente si construim o lista valida de invitati bazata pe valorile de 
adevar determinate.

Complexitate: O(N + M)
