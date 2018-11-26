/*
// Contains dynamic casting and Longest common subsequence
You are battling a powerful dark wizard. He casts his spells from a distance,
giving you only a few seconds to react and conjure your counterspells. For a
counterspell to be effective, you must first identify what kind of spell you are
dealing with.

The wizard uses scrolls to conjure his spells, and sometimes he uses some of his
generic spells that restore his stamina. In that case, you will be able to
extract the name of the scroll from the spell. Then you need to find out how
similar this new spell is to the spell formulas written in your spell journal.

Spend some time reviewing the locked code in your editor, and complete the body
of the counterspell function.

Check Dynamic cast to get an idea of how to solve this challenge.

Input Format

The wizard will read t scrolls, which are hidden from you.
Every time he casts a spell, it's passed as an argument to your counterspell
function.

Output Format

After identifying the given spell, print its name and power.
If it is a generic spell, find a subsequence of letters that are contained in
both the spell name and your spell journal. Among all such subsequences, find
and print the length of the longest one on a new line.

Sample Input

3
fire 5
AquaVitae 999 AruTaVae
frost 7

Sample Output

Fireball: 5
6
Frostbite: 7

Explanation

Fireball and Frostbite are common spell types.
AquaVitae is not, and when you compare it with AruTaVae in your spell journal,
you get a sequence: AuaVae

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define max(a, b) a > b ? a : b

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char *X, char *Y, int m, int n) {
  int L[m + 1][n + 1];
  int i, j;

  /* Following steps build L[m+1][n+1] in bottom up fashion. Note
     that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
  for (i = 0; i <= m; i++) {
    for (j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        L[i][j] = 0;

      else if (X[i - 1] == Y[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;

      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    }
  }

  /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
  return L[m][n];
}

class Spell {
 private:
  string scrollName;

 public:
  Spell() : scrollName("") {}
  Spell(string name) : scrollName(name) {}
  virtual ~Spell() {}
  string revealScrollName() { return scrollName; }
};

class Fireball : public Spell {
 private:
  int power;

 public:
  Fireball(int power) : power(power) {}
  void revealFirepower() { cout << "Fireball: " << power << endl; }
};

class Frostbite : public Spell {
 private:
  int power;

 public:
  Frostbite(int power) : power(power) {}
  void revealFrostpower() { cout << "Frostbite: " << power << endl; }
};

class Thunderstorm : public Spell {
 private:
  int power;

 public:
  Thunderstorm(int power) : power(power) {}
  void revealThunderpower() { cout << "Thunderstorm: " << power << endl; }
};

class Waterbolt : public Spell {
 private:
  int power;

 public:
  Waterbolt(int power) : power(power) {}
  void revealWaterpower() { cout << "Waterbolt: " << power << endl; }
};

class SpellJournal {
 public:
  static string journal;
  static string read() { return journal; }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
  Fireball *fb = dynamic_cast<Fireball *>(spell);
  if (fb) {
    fb->revealFirepower();
    return;
  }
  Frostbite *frb = dynamic_cast<Frostbite *>(spell);
  if (frb) {
    frb->revealFrostpower();
    return;
  }
  Thunderstorm *ts = dynamic_cast<Thunderstorm *>(spell);
  if (ts) {
    ts->revealThunderpower();
    return;
  }
  Waterbolt *wb = dynamic_cast<Waterbolt *>(spell);
  if (wb) {
    wb->revealWaterpower();
    return;
  }

  string scrollName = spell->revealScrollName();
  string journal = SpellJournal::read();
  int m = scrollName.length();
  int n = journal.length();
  int len[m + 1][n + 1];
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        len[i][j] = 0;
      else if (scrollName[i - 1] == journal[j - 1])
        len[i][j] = len[i - 1][j - 1] + 1;
      else
        len[i][j] = max(len[i][j - 1], len[i - 1][j]);
    }
  }
  cout << len[m][n] << endl;
}

class Wizard {
 public:
  Spell *cast() {
    Spell *spell;
    string s;
    cin >> s;
    int power;
    cin >> power;
    if (s == "fire") {
      spell = new Fireball(power);
    } else if (s == "frost") {
      spell = new Frostbite(power);
    } else if (s == "water") {
      spell = new Waterbolt(power);
    } else if (s == "thunder") {
      spell = new Thunderstorm(power);
    } else {
      spell = new Spell(s);
      cin >> SpellJournal::journal;
    }
    return spell;
  }
};

int main() {
  int T;
  cin >> T;
  Wizard Arawn;
  while (T--) {
    Spell *spell = Arawn.cast();
    counterspell(spell);
  }
  return 0;
}