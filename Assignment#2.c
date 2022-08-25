#include<stdio.h>

struct node{
    int val ,row ,clm;
    struct node *right,*down;
};

struct node *Row_head1 = NULL, *Row_head2 = NULL, *ans_r_head = NULL; // for row and column numbers
struct node *Column_head1 = NULL, *Column_head2 = NULL, *ans_c_head = NULL;

void Make_row_head(int n){

    for(int i = 1; i<=n; i++){

        struct node*temp = (struct node*)malloc(sizeof(struct node*));
        temp->val = 0;
        temp->clm = 0;
        temp->row = i;

        if(Row_head1== NULL){    //for matrix 1
            Row_head1 = temp;
        }
        else{
            struct node *test = Row_head1;

            while(test->down != NULL){
                test = test->down;
            }
            test->down = temp;
        }

        if(Row_head2== NULL){   //for matrix 2
            Row_head2 = temp;
        }
        else{
            struct node *test = Row_head2;

            while(test->down != NULL){
                test = test->down;
            }
            test->down = temp;
        }

        if(ans_r_head== NULL){   //for matrix 2
            ans_r_head = temp;
        }
        else{
            struct node *test  = ans_r_head;

            while(test->down != NULL){
                test = test->down;
            }
            test->down = temp;
        }
    }
}

void Make_column_head(int n){

    for(int i = 1; i<=n; i++){

        struct node*temp = (struct node*)malloc(sizeof(struct node*));
        temp->val = 0; 
        temp->row = 0;
        temp->clm = i;

        if(Column_head1 == NULL){
            Column_head1 = temp;
        }
        else{
            struct node*test = Column_head1;

            while(test->right != NULL){
                test = test->right;
            }
            test->right = temp;
        }

        if(Column_head2 == NULL){
            Column_head2 = temp;
        }
        else{
            struct node*test = Column_head2;

            while(test->right != NULL){
                test = test->right;
            }
            test->right = temp;
        }
        
        if(ans_c_head == NULL){
            ans_c_head = temp;
        }
        else{
            struct node*test = ans_c_head;

            while(test->right != NULL){
                test = test->right;
            }
            test->right = temp;
        }

    }
}

int main(){

   int n,mat_num;
   scanf("%d", &n);
   
   Make_row_head(n);   // allocating space to the link list for row number
   Make_column_head(n); // allocatoing space to the link list for column number

   scanf("&d", &mat_num);

   while(mat_num!=0){
        int row,column,val;

        if(mat_num == 1){
            
        scanf("%d%d%d",&row, &column, &val);
        }

   }


   

}
