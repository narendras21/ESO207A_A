#include<stdio.h>
#include<stdlib.h>

struct node{
    int val ,row ,clm;
    struct node *right,*down;
};

struct node *Row_head1 = NULL, *Row_head2 = NULL, *ans_r_head = NULL; // for row and column numbers
struct node *Column_head1 = NULL, *Column_head2 = NULL, *ans_c_head = NULL;

void Make_row_head(int n){

    for(int i = 1; i<=n; i++){

        struct node*temp = (struct node*)malloc(1*sizeof(struct node*));

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

        // if(Row_head2== NULL){   //for matrix 2
        //     Row_head2 = temp;
        // }
        // else{
        //     struct node *test = Row_head2;

        //     while(test->down != NULL){
        //         test = test->down;
        //     }
        //     test->down = temp;
        // }

        // if(ans_r_head== NULL){   //for matrix 2
        //     ans_r_head = temp;
        // }
        // else{
        //     struct node *test  = ans_r_head;

        //     while(test->down != NULL){
        //         test = test->down;
        //     }
        //     test->down = temp;
        // }
    }
}

void Make_column_head(int n){

    for(int i = 1; i<=n; i++){

        struct node*temp = (struct node*)malloc(sizeof(struct node*));
        temp->val = 0; 
        temp->row = 0;
        temp->clm = i;

        // if(Column_head1 == NULL){
        //     Column_head1 = temp;
        // }
        // else{
        //     struct node*test = Column_head1;

        //     while(test->right != NULL){
        //         test = test->right;
        //     }
        //     test->right = temp;
        // }

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
        
        // if(ans_c_head == NULL){
        //     ans_c_head = temp;
        // }
        // else{
        //     struct node*test = ans_c_head;

        //     while(test->right != NULL){
        //         test = test->right;
        //     }
        //     test->right = temp;
        // }

    }
}

struct node* Make_node(int val, int row, int column){

    struct node *new = (struct node*)malloc(1*sizeof(struct node*));
    new->val = val;
    new->row = row;
    new->clm = column;

    return new;
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
        
        struct node *temp_row = Row_head1, *temp_column = Column_head1;

        for(int i = 1; i<=row; i++){
            temp_row = temp_row->down;
        }
        while(temp_row->right != NULL){
            temp_row = temp_row->right;
        }

        for(int i = 1; i<=column; i++){
            temp_column = temp_column->right;
        }
        while(temp_column->down != NULL){
            temp_column = temp_column->down;
        }

        struct node *insert = Make_node(val,row,column);

        temp_row->right = insert;
        temp_column->down = insert;

        }

        else if(mat_num == 2){

            scanf("%d%d%d",&row, &column, &val);
            struct node *temp_row = Row_head2, *temp_column = Column_head2;

            for(int i = 1; i<=row; i++){
                temp_row = temp_row->down;
            }
            while(temp_row->right != NULL){
                temp_row = temp_row->right;
            }

            for(int i = 1; i<=column; i++){
                temp_column = temp_column->right;
            }
            while(temp_column->down != NULL){
                temp_column = temp_column->down;
            }

            struct node *insert = Make_node(val,row,column);

            temp_row->right = insert;
            temp_column->down = insert;

            }
        
        scanf("%d",&mat_num);
    }

struct node *temp_row = Row_head1,*temp_column = Column_head2;

for(int i = 1; i<=n; i++){

    for(int k = 1; k<i; k++){
        temp_row = temp_row->down;
    }

    int sum = 0,j = 1;

    for(j = 1; i<=n; j++){

       for(int k = 1; k<j; k++){
        temp_column = temp_column->right;
       }

       if(temp_row->right != NULL){
        temp_row = temp_row->right;
       }
       else{
        break;
       }

       if(temp_column->down != NULL){
        temp_column = temp_column->down;
       }
       else break;

       if(temp_row->clm == temp_column->row){
        sum += (temp_row->val)*(temp_column->val);
       }
    }
    printf("%d %d %d\n",i,j,sum);

    temp_row = Row_head1;
    temp_column = Column_head2;
}

return 0;
 }



