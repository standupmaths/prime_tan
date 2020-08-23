#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gmp.h>

mpz_t temp_h;
mpz_t temp_k;
mpf_t temp_f;
mpf_t temp_f2;

void get_cf(mpf_t r, mpz_t h, mpz_t k, mpz_t h_old, mpz_t k_old, mpz_t a){
	mpz_set_f(a, r);
	mpf_set_z(temp_f, a);
	mpf_sub(r, r, temp_f);
	mpf_ui_div(r, 1, r);

	mpz_mul(temp_h, a, h);
	mpz_add(temp_h, temp_h, h_old);
	mpz_mul(temp_k, a, k);
	mpz_add(temp_k, temp_k, k_old);

	mpz_set(h_old, h);
	mpz_set(k_old, k);
	mpz_set(h, temp_h);
	mpz_set(k, temp_k);
}

int main(int argc, char **argv){
	mpf_t r;
	mpz_t h;
	mpz_t k;
	mpz_t h_old;
	mpz_t k_old;
	mpz_t a;
	int i;
	double d;

	if(argc > 1){
		//Allow the user to specify a default precision using a command-line argument
		mpf_set_default_prec(atoi(argv[1]));
	}

	mpf_init(r);
	mpf_init(temp_f);
	mpf_init(temp_f2);

	mpz_init(temp_h);
	mpz_init(temp_k);
	mpz_init(h);
	mpz_init(k);
	mpz_init(h_old);
	mpz_init(k_old);
	mpz_init(a);

	mpf_set_d(r, M_PI/2);

	mpz_set_si(h, 1);
	mpz_set_si(k_old, 1);

	for(i = 0; i < 10; i++){
		get_cf(r, h, k, h_old, k_old, a);
		if(mpz_odd_p(k)){
			printf("candidate: ");
			mpz_out_str(stdout, 0, h);
			printf("\n");
		}
	}

	mpf_clear(r);
	mpf_clear(temp_f);
	mpf_clear(temp_f2);

	mpz_clear(temp_h);
	mpz_clear(temp_k);
	mpz_clear(h);
	mpz_clear(k);
	mpz_clear(h_old);
	mpz_clear(k_old);
	mpz_clear(a);
}

