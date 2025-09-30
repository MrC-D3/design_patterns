// A) Inizializzo l'algoritmo prendendo il primo valore dell'array che fa da
//  elemento di confronto e da root dell'albero; lo chiamiamo R.
// B) Quindi leggo tutti gli elementi dell'array da array[1] in poi e in un 
//  array parallelo inserisco 0 per i valori minori di R e 1 per i valori 
//  maggiori.
// C) Quindi leggo l'array parallelo e al primo 0 rendo il rispettivo valore la
//  la root R0 e al primo 1 ottengo invece R1.
// D) I valori-0 minori di R0 diventano i valori-00 e quelli maggiori valori-01,
//  mentre i valori-1 diventano valori-10 e valori-11.
// E) Quindi ripeto lo step C identificando le root R00, R01, R10, R11.

// Poi posso costruire un albero che andrebbe letto left-parent-right per avere
//  l'array ordinato.
// Oppure posso memorizzare quanti valori minori di ciascuna root ci sono.

// Le roots le posso memorizzare in una lista di root: prima 1, poi 2, poi 4...

// Il vettore di binaries può essere una lista da cui tolgo gli indici di chi è
// diventato root.

// Comunque alla fine è una rivisitazione del Quicksort: nel caso peggiore costa
//  N^2. Anzi, forse è peggio perchè switcho tra strutture dati quindi no
//  data locality.

#include <vector>
#include <iostream>


struct NodeT
{
    int value;
    NodeT* left = nullptr;
    NodeT* right = nullptr;
};

void read_tree(NodeT* root);

void tree_sort(int array[], int size)
{
    // A + B, lettura 1.
    NodeT R;
    R.value = array[0];
    char binaries[6];
    binaries[0] = 0b10000000; // MSB set: it's a parent.    
    for(int i = 1; i < size; i++)
    {
        if(array[i] < R.value)
        {
            binaries[i] = 0b00000000; // MSB: not a parent; LSB: < than the root.
        }
        else
        {
            binaries[i] = 0b00000001; // ...; LSB: greater than the root.
        }
    }

    // C + D, lettura 2.
    NodeT R0;
    NodeT R1;
    R0.value = -1;
    R1.value = -1;
    for(int i = 1; i < size; i++)
    {
        if(binaries[i] == 0b00000000) // One LSB at 0.
        {
            if(R0.value == -1)
            {
                R0.value = array[i];
                binaries[i] |= 0b10000000;
                R.left = &R0;
            }
            else
            {
                if(array[i] < R0.value)
                {
                    binaries[i] = 0b00000000; // Two LSBs.
                }
                else
                {
                    binaries[i] = 0b00000001; // Two LSBs.
                }
            }
        }
        else
        {
            if(R1.value == -1)
            {
                R1.value = array[i];
                binaries[i] |= 0b10000000; 
                R.right = &R1;
            }
            else
            {
                if(array[i] < R1.value)
                {
                    binaries[i] = 0b00000010; // Two LSBs.
                }
                else
                {
                    binaries[i] = 0b00000011; // Two LSBs.
                }
            }
        }
    }

    // E, lettura 3.
    NodeT R00;
    NodeT R01;
    NodeT R10;
    NodeT R11;
    R00.value = -1;
    R01.value = -1;
    R10.value = -1;
    R11.value = -1;
    for(int i = 0; i < size; i++)
    {
        if((binaries[i] & 0b10000000) == 0b10000000)
        {
            continue;
        }

        if(binaries[i] == 0b00000000) // Two LSB at 00.
        {
            if(R00.value == -1)
            {
                R00.value = array[i];
                binaries[i] |= 0b10000000;
                R0.left = &R00;
            }
            else
            {
                if(array[i] < R00.value)
                {
                    binaries[i] = 0b00000000; // Three LSBs: 000.
                }
                else
                {
                    binaries[i] = 0b00000001; // Three LSBs: 001.
                }
            }
        }
        else if(binaries[i] == 0b00000001) // Two LSB at 01.
        {
            if(R01.value == -1)
            {
                R01.value = array[i];
                binaries[i] |= 0b10000000;
                R0.right = &R01;
            }
            else
            {
                if(array[i] < R01.value)
                {
                    binaries[i] = 0b00000010; // Three LSBs: 010.
                }
                else
                {
                    binaries[i] = 0b00000011; // Three LSBs: 011.
                }
            }
        }
        else if(binaries[i] == 0b00000010) // Two LSB at 10.
        {
            if(R10.value == -1)
            {
                R10.value = array[i];
                binaries[i] |= 0b10000000;
                R1.left = &R10;
            }
            else
            {
                if(array[i] < R10.value)
                {
                    binaries[i] = 0b00000100; // Three LSBs: 000.
                }
                else
                {
                    binaries[i] = 0b00000101; // Three LSBs: 001.
                }
            }
        }
        else // Two LSB at 11.
        {
            if(R11.value == -1)
            {
                R11.value = array[i];
                binaries[i] |= 0b10000000;
                R1.right = &R11;
            }
            else
            {
                if(array[i] < R11.value)
                {
                    binaries[i] = 0b00000110;
                }
                else
                {
                    binaries[i] = 0b00000111;
                }
            }
        }
    }

    // E, lettura 4.
    NodeT R000, R001, R010, R011, R100, R101, R110, R111;
    R000.value = R001.value = R010.value = R011.value = R100.value = R101.value = R110.value = R111.value = -1;
    for(int i = 0; i < size; i++)
    {
        if((binaries[i] & 0b10000000) == 0b10000000)
        {
            continue;
        }

        if(binaries[i] == 0b00000000) // Three LSB at 000.
        {
            if(R000.value == -1)
            {
                R000.value = array[i];
                binaries[i] |= 0b10000000;
                R00.left = &R000;
            }
            else
            {
                if(array[i] < R000.value)
                {
                    binaries[i] = 0b00000000; // 4 LSBs: 000.
                }
                else
                {
                    binaries[i] = 0b00000001; // 4 LSBs: 0001.
                }
            }
        }
        else if(binaries[i] == 0b00000001) // 3 LSB at 001.
        {
            if(R001.value == -1)
            {
                R001.value = array[i];
                binaries[i] |= 0b10000000;
                R00.right = &R001;
            }
            else
            {
                if(array[i] < R001.value)
                {
                    binaries[i] = 0b00000010; // Three LSBs: 010.
                }
                else
                {
                    binaries[i] = 0b00000011; // Three LSBs: 011.
                }
            }
        }
        else if(binaries[i] == 0b00000010) // 3 LSB at 010.
        {
            if(R010.value == -1)
            {
                R010.value = array[i];
                binaries[i] |= 0b10000000;
                R01.left = &R010;
            }
            else
            {
                if(array[i] < R010.value)
                {
                    binaries[i] = 0b00000100; // Three LSBs: 000.
                }
                else
                {
                    binaries[i] = 0b00000101; // Three LSBs: 001.
                }
            }
        }
        else // 3 LSB at 011.
        {
            if(R011.value == -1)
            {
                R011.value = array[i];
                binaries[i] |= 0b10000000;
                R01.right = &R011;
            }
            else
            {
                if(array[i] < R011.value)
                {
                    binaries[i] = 0b00000110;
                }
                else
                {
                    binaries[i] = 0b00000111;
                }
            }
        }
    }

    // Read the tree.
    read_tree(&R);
}

void read_tree(NodeT* root)
{
    if(root == nullptr)
        return;

    read_tree(root->left);
    std::cout << "Node value: " << root->value << ".\n";
    read_tree(root->right);
}


int main()
{
    int array[6] = {5, 9, 1, 3, 11, 2};
    tree_sort(array, 6);

    return 0;
}