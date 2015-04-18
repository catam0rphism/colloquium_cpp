natural ADD_1N_N(const natural n) {
	natural res = n;
	res.digits[0]++;

	if(res.digits[0] == 10) {
		res.digits[0]-= 10;
		res.digits[1]++;
	}
	return res;
};
