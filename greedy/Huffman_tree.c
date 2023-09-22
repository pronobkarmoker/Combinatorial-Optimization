#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_NODES 256

int size;

struct Node
{
    char data;
    int freq;
    struct Node *left, *right;
};

struct Frequency
{
    char data;
    int freq;
};

void huffmanCoding(char *data, int *freq);
struct Node *buildHuffmanTree(struct Frequency *freqTbable);
struct Node *createNode(char data, int freq);
void printHuffmanCodes(struct Node *root, char *code, int top);

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("huffmaninput.txt", "r");

    // printf("Enter size:");
    fscanf(fp, "%d", &size);
    char data[size];
    int freq[size];

    // printf("Enter character and frequency:\n");
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, " %c %d", &data[i], &freq[i]);
    }
    fclose(fp);

    huffmanCoding(data, freq);

    return 0;
}

void huffmanCoding(char *data, int *freq)
{
    struct Frequency freqTable[MAX_TREE_NODES];

    for (int i = 0; i < size; i++)
    {
        freqTable[i].data = data[i];
        freqTable[i].freq = freq[i];
    }

    struct Node *root = buildHuffmanTree(freqTable);

    char code[MAX_TREE_NODES];
    int top = 0;

    printf("Huffman Codes:\n");
    printHuffmanCodes(root, code, top);
}

struct Node *buildHuffmanTree(struct Frequency *freqTbable)
{
    struct Node *treeNodes[MAX_TREE_NODES];
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        treeNodes[i] = createNode(freqTbable[i].data, freqTbable[i].freq);
        count++;
    }
    while (count > 1)
    {
        int low1 = 0, low2 = 1;

        if (treeNodes[low1]->freq > treeNodes[low2]->freq)
        {
            int temp = low1;
            low1 = low2;
            low2 = temp;
        }
        for (int i = 2; i < count; i++)
        {
            if (treeNodes[i]->freq < treeNodes[low1]->freq)
            {
                low2 = low1;
                low1 = i;
            }
            else if (treeNodes[i]->freq < treeNodes[low2]->freq)
            {
                low2 = i;
            }
        }
        struct Node *combinedNode = createNode('\0', treeNodes[low1]->freq + treeNodes[low2]->freq);
        combinedNode->left = treeNodes[low1];
        combinedNode->right = treeNodes[low2];

        treeNodes[low1] = combinedNode;
        treeNodes[low2] = treeNodes[count - 1];
        count--;
    }
    return treeNodes[0];
}

struct Node *createNode(char data, int freq)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printHuffmanCodes(struct Node *root, char *code, int top)
{
    if (root->left)
    {
        code[top] = '0';
        printHuffmanCodes(root->left, code, top + 1);
    }

    if (root->right)
    {
        code[top] = '1';
        printHuffmanCodes(root->right, code, top + 1);
    }

    if (root->left == NULL && root->right == NULL)
    {
        code[top] = '\0';
        printf("%c: %s\n", root->data, code);
    }
}