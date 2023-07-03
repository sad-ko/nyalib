#include <nyalib.h>
#include <stdio.h>
#include <string.h>

int nyan() {
  Result rc = Nyatring_new("hello everynyan", 16);
  autoNyatring nya;

  switch (rc.res) {
  case Ok:
    nya = (castNyatring)rc.data;
    nyuts(nya->str);
    pryant("Nyatring size: %lu\n", Nyatring_size(nya));
    break;

  case Err:
    fpryant(nyaerr, "[NYARROR] - Invalid nyatring\n");
    break;
  }

  Result rc2 = Nyatring_new(", how are you? fine thank you", 30);
  autoNyatring nya2 = (castNyatring)nyawrap(&rc2);

  Nyatring_cat(nya, nya2);
  nyuts(nya->str);

  pryant("nyan found in nyatring: %s", Nyatring_find(nya, "nyan"));

  nyaturn(0);
}
