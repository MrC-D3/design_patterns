// Priority queue: struttura dati dove ho in testa l'elemento con la chiave più
//  grande; per il resto, non abbiamo alcuna garanzia sull'ordinamento degli
//  altri suoi elementi.
// Heap: è l'implementazione più comune di una priority queue. Graficamente è un
//  albero binario che ha nella radice il suo elemento a priorità maggiore e in
//  cui ogni nodo intermedio è maggiore di entrambi i suoi figli. A livello
//  implementativo è un array in cui i figli di array[i] sono array[2i] e 
//  array[2i+1] per i>0 (infatti non si usa l'indice 0 o non varrebbe la 
//  regola). Questa relazione tra il padre e i suoi figli permette di 
//  ripristinare facilmente l'heap quando viene modificato (nodo rimosso, 
//  aggiunto, ecc.). Si parla anche di Albero Heap-ordinato.
// Costo di costruzione dell'heap: N. Infatti, partendo dalla fine dell'heap e
//  sfruttando la regola che il padre di array[i] è array[int(i/2)], posso 
//  scambiare i due valori qualora array[i] fosse maggiore di array[int(i/2)].
//  Quindi leggendo una sola volta l'array, riuscirei a costruire l'heap.
// Costo di eliminazione del massimo: LogN. Infatti, mentre trovare il massimo
//  ha costo 1, perchè sappiamo essere nella radice, eliminarlo vuol dire
//  scambiarlo con l'ultima, ridurre di 1 la dimensione dell'array e 
//  ripristinare l'heap scambiando la nuova radice col più grande dei figli e 
//  così via.

// TODO: implementazione di una priority queue mediante heap. La C++ standard
//  library la implementa già in <queue>: std::priority_queue.


// Heapsort: algoritmo di ordinamento che consiste nel ripetere l'operazione di
//  "rimozione del massimo" N volte (quindi con costo N*LogN), cioè costruendo
//  l'array ordinato dal fondo. Se invece siamo interessati nel K-esimo elemento
//  più grande, possiamo fermare l'algorimo all'iterazione K.
// Confronti: l'heapsort condivide con il quicksort il non essere stabile, ma
//  sfruttare la località dei dati (buono per la cache) e non usare memoria
//  aggiuntiva (cose opposte al mergesort). Al contrario del QuickSort però, non
//  esiste un input che lo fa performare peggio. Tuttavia, nel caso medio, il 
//  QuickSort risulta ancora l'algoritmo migliore.
// Ottimizzazione: uso di un albero ternario invece che binario (si è visto che
//  avere ancora più figli invece non da miglioramenti).

// TODO: implementazione dell'HeapSort.


// Albero Binario Heap-ordinato a Sinistra (Leftist Heap): albero binario in cui
//  la radice non ha il figlio destro e il figlio sinistro è un Albero 
//  Heap-ordinato. Il vantaggio di questo albero è che permette l'unione di 2 
//  alberi facilmente, cosa che per gli Alberi Heap-ordinati era invece 
//  complessa. Qui infatti, da 2 Leftist Heap con radici A e B, posso rendere A
//  il figlio sinistro di B e il vecchio figlio sinistro di B diventa il figlio
//  destro di A (eventualmente poi dovrò ripristinare l'heap se A è minore del
//  vecchio figlio destro).
// Albero Binomiale (o Heap Potenza di 2): struttura dati ricorsiva in cui 
//  l'Albero Binomiale B_k è l'unione di due alberi B_k-1, dove B_0 è il singolo
//  nodo.
// Heap Binomiale (o Coda Binomiale): collezione di Alberi Binomiali, in cui per
//  ogni grado K ho al più un Albero Binomiale B_k. Una Coda Binomiale di N
//  elementi ha un Heap Potenza di 2 per ogni uno della sua rappresentazione 
//  binaria, quindi al più LogN (nel caso in cui tutti 1). La proprietà
//  principale di questa collezione è che il merge di 2 Heap Binomiali coincide 
//  con l'aritmetica binaria: 2 B_0 generano un B_1 di riporto e un B_0 vuoto.
// Costi:
// - O(N) per la costruzione di una Coda Binomiale di N elementi;
// - O(LogN) per tutte le operazioni di una coda con priorità implementata 
//  usando una Coda Binomiale, quindi anche per l'estrazione del massimo che 
//  consiste nel leggere tutte le radici degli Heap Potenza di 2 (al più LogN).

// TODO: implementazione di una coda binomiale mediante un array di puntatori
//  alle radici di ciascun Albero Binomiale nella coda; più, implementazione
//  di tutte le operazioni di una coda con priorità che usa la coda binomiale.