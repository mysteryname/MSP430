/* * Delay function. **/
delay(unsigned int d) {
	int i;
	for (i = 0; i<d; i++) {
		__delay_cycles(1000); // 1ms aprrox. 
	}
}

