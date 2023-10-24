//따옴표 별 사용법
[큰 따옴표] - 문자열을 저장할때
1. 사용하면 문자열뒤에 NULL값이 들어감
2. char str[] = "Good Morning";
3. 문자열 저장이나 출력은 % s -> / \0까지 읽음


[작은 따옴표] - 문자 하나(단어) 를 저장할때
1. 배열이 아니더라도 char str = 'a';
2. char str[] = { 'g', 'o', 'o','d' };
3. 문자 저장이나 출력은 무조건 % c


//문자열의 길이를 저장하고 출력
int main(void) {
    // 문자열을 선언하고 초기화합니다.
    char str[] = "a barking dog never bites";
    int i = 0; // 문자열의 길이를 저장할 변수

    //문자열의 마지막 값에는 NULL \0의 값이 들어가있기 때문에 0이나오면 반복을 종료한다 - 문자열의 길이를 계산하는 반복문
    while (str[i] != '\0') {
        i++;
    }
    //int i = strlen(str); //#include <string.h> 라이브러리 함수를 사용할 수도 있음

    // 문자열의 길이를 출력
    printf("문자열 %s의 길이는  %d입니다.", str, i);

    return 0; // 프로그램 종료를 나타내는 반환값
}


//크기보다 더큰값을 끝에붙혀넣거나 복사를 한다면?
int main(void) {
    char src[13] = "hello";
    char dst[] = "world"; //배열의 크기를 지정하고 strcpy()함수를 사용하게되면 쓰레기값이 들어감 이유는 모름

    //strcpy(dst, src); //src의 값을 dst에 복사
    strcat(src, dst);   //src의 값을 dst끝에 붙혀넣기

    //(sizeof(src) - (strlen(src) + 1)) 남은 배열의 값을 구해서 남은크기많큼 뒤에 값 넣기 +1을 하는 이유는 \0크기 포함
    strncat(src, dst,(sizeof(src)-(strlen(src)+1)));
    printf("%s", src);


    //크기보다 더큰값을 끝에붙혀넣거나 복사를 한다면 ?
    //결과 : 경고:C6386	'dst'에 쓰는 동안 버퍼 오버런이 발생
}
