#define STACK_LENGTH 10

static double stack[STACK_LENGTH];
static int position = 0;

void push(void);
double pop(void);
void printStack(void);