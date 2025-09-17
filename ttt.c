#include <stdio.h>
#include <stdbool.h>

bool board_full(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') { // empty spot found
                return false;
            }
        }
    }
    return true; // no empty spots
}

char check_win(char board[3][3], char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) {
            return p;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == p && board[1][j] == p && board[2][j] == p) {
            return p;
        }
    }

    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return p;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return p;

    if (board_full(board)) {
    	return 'd';
    }

    return ' ';
}

void print_board(char board[3][3]) {
     for (int i = 0; i<3; i++) {
            for (int j = 0; j<3; j++) {
                printf("%c", board[i][j]);
                if (j < 2) {
                    printf(" | ");
                }
            }
        printf("\n");
    }
}

void ttt () {
    printf("\e[1;1H\e[2J"); //clear screen
    char board[3][3] = {
	    		{'-', '-', '-'}, 
	    		{'-', '-', '-'},
			{'-', '-', '-'}
    };
    
    int turn = 1;
    char players[2] = {'X', 'O'};
    char winner = '-';
    //1 = X 2 = O

    while(winner == '-') {
	    printf("\e[1;1H\e[2J");
	    print_board(board);
	    //game
	    printf("Player %d (%c) \n", turn, players[turn-1]);

	    int r; int c;

	    printf("Choose row: ");
	    scanf("%d", &r);

	    printf("Choose col: ");
	    scanf("%d", &c);

	    if (r > 3 || r < 1 || c > 3 || c < 1) {
	    	printf("invalid input \n");
	    	continue;
	    }

	    if (board[r-1][c-1] != '-') {
	    	printf("Space already filled \n");
	    	continue;
	    }
		
	    board[r-1][c-1] = players[turn-1];

	    print_board(board);
	    if (check_win(board, players[turn-1]) == 'd') {
		printf("\e[1;1H\e[2J");
		print_board(board);
		printf("The game is a draw \n");
		break;
	    }
	    else if (check_win(board, players[turn-1]) == players[turn-1]) {
		printf("\e[1;1H\e[2J");
		print_board(board);
	    	printf("winner is player %d (%c) \n", turn, players[turn-1]);
		break;
	    }

	    if (turn == 1) {
		turn++;
	    }
	    else{
		turn--;
	    }
    }
}

int main() {
        ttt();
        return 0;
}
