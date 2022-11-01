#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define WORD_NUM 5
#define WORD_MAX_LEN 20
#define ALPHABET 26
#define DEADLINE 6

void print_Screen(char* word, int wrong_cnt, int deadline, int* picked_list); //화면 출력 함수 
int lower(char* alpha); //알파벳을 소문자로 변경, 알파벳 범위일시 1, 아니면 0 반환
int pick_Word(int word_num); //단어 선택 함수, 선택한 단어의 index 반환
int is_finish(int wrong_cnt, int deadline, char* word, int* picked_list); //승패 결정함수, 이기면 1, 지면 -1, 끝나지 않았으면 0 반환
int is_in(char* word, char character); //입력된 문자가 단어 안에 있으면 1 없으면 0 반환


int main() {

	char word_list[WORD_NUM][WORD_MAX_LEN] = { "apple","banana","melon","mango","grape" };
	char input;
	int picked_list[ALPHABET] = { 0 };
	int picked_index = pick_Word(WORD_NUM);
	int wrong_cnt = 0;
	int fin = 0;
	

	do {
		print_Screen(word_list[picked_index], wrong_cnt, DEADLINE, picked_list);
		
		do {
			printf("\n\nPlease enter the alphabet : ");
			scanf(" %c", &input);
		} while (!lower(&input));

		if (!is_in(word_list[picked_index], input)) wrong_cnt++;

		picked_list[input-'a'] = 1;
		fin = is_finish(wrong_cnt,DEADLINE, word_list[picked_index], picked_list);
	} while (!fin);//do while end

	print_Screen(word_list[picked_index], wrong_cnt, DEADLINE, picked_list);


	if (fin == 1) printf("\n\nYou Win!!!!\n\n");
	else printf("\n\nYou Lose...\n\n");


}// main() end


void print_Screen(char* word,int wrong_cnt, int deadline, int* picked_list) {
	

	char person[6] = { 'o','(','|',')','(',')' };

	for (int i = wrong_cnt; i < sizeof(person); i++) {
		person[i] = ' ';
	}

	system("cls");

	printf("======Hang Man======\n\n");
	printf("        life:%2d/%2d\n", wrong_cnt, deadline);
	printf("         ---------\n");
	printf("         |       |\n");
	printf("         %c       |\n", person[0]);
	printf("       %c %c %c     |\n", person[1], person[2], person[3]);
	printf("        %c %c      |\n", person[4], person[5]);
	printf("                 |\n");
	printf("              ------\n\n");
	
	
	for (int i = 0; i < strlen(word); i++){
		
		if (picked_list[word[i] - 'a']) printf("%c ", word[i]);
		else printf("_ ");

	}//for end //입력된 알파벳 출력, 아니면 _ 출력


	printf("\n\nWords already entered :\n");
	
	for (int i = 0; i < 26; i++) {
		if (picked_list[i]) printf("%c ", i + 'a');
	}

	printf("\n");

}//print_Screen() end


int pick_Word(int word_num) {

	srand(time(NULL));
	
	return rand() % word_num;

}//pick_Word() end

int lower(char* alpha) {

	if (*alpha >= 'A' && *alpha <= 'Z') {
		*alpha += 32;
	}
	else if (*alpha < 'a' || *alpha > 'z') {
		return 0;
	}
	return 1;
}//lower() end


int is_finish(int wrong_cnt, int deadline, char* word, int* picked_list) {

	if (deadline < wrong_cnt) return -1;
	
	int win_check = 1;

	for (int i = 0; i < strlen(word); i++) {
		if (picked_list[word[i]-'a'] == 0) win_check = 0;
	}//for end

	return win_check;

}//is_finish() end


int is_in(char *word, char character) {
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] == character) return 1;
	}
	return 0;
}//is_in() end