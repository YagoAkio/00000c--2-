#include <windows.h>
#include <stdio.h>
#include <time.h>

int main() {
    POINT cursorPos;
    while(1){
    	if ((GetAsyncKeyState(VK_LBUTTON) & 0x8001)==1){
    		GetCursorPos(&cursorPos);
    		printf("Posição do mouse: X = %d, Y = %d\n", cursorPos.x, cursorPos.y);
    	} 
        	   	    
    }
    

    return 0;
}

