//Defines and macros
#define SYSTEM_MALLOC 1
#define STRUCT_SIZE 24 
#define MULTIPLIER 10
#define ALIGN_SIZE 8
#define ALIGN(size) (((size) + (ALIGN_SIZE-1)) & ~(ALIGN_SIZE-1))

// --- Struct to store memory's block metadata
typedef struct chunkStatus
{
  int size;
  int available;
  struct chunkStatus* next;
  struct chunkStatus* prev;
  char end[1]; 		//end represents the end of the metadata struct
} chunkStatus;


chunkStatus* findChunk(chunkStatus *headptr, unsigned int size);

void splitChunk(chunkStatus* ptr, unsigned int size);

chunkStatus* increaseAllocation(chunkStatus *tailptr, unsigned int size);

void mergeChunk(chunkStatus *freed);

void printList(chunkStatus *headptr);

void *mymalloc(unsigned int _size);

unsigned int myfree(void *ptr);
