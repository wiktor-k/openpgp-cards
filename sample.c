#include "openpgp_cards.h"
#include <stdio.h>

int main() {
  CCards *cards = 0;
  printf("result: %d\n", opc_scan_for_cards(&cards));
  int cards_num = opc_get_cards_len(cards);
  printf("Cards: %d\n", cards_num);
  for (int i = 0; i < cards_num; i++) {
    printf("  - %s\n", opc_get_card_ident(cards, i));
    printf("    SIG: %s\n", opc_get_card_sig_fpr(cards, i));
    printf("    DEC: %s\n", opc_get_card_dec_fpr(cards, i));
    printf("    AUT: %s\n", opc_get_card_aut_fpr(cards, i));
  }
  opc_free_cards(cards);
  return 0;
}
