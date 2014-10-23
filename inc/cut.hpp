#ifndef H_CUT
#define H_CUT

#include <string>
#include <set>

class Cut{
public:
  explicit Cut(const std::string& cut_string="");
  Cut(const std::string& cut_string,
      const std::set<std::string>& dependencies);
  Cut(const std::string& cut_string,
      const std::string& dependencies);

  const std::set<std::string>& Dependencies() const;
  std::set<std::string>& Dependencies();

  const std::string& CutString() const;
  std::string& CutString();

  bool operator<(const Cut& cut) const;

  Cut& operator&=(const Cut& cut);
  Cut& operator|=(const Cut& cut);
  Cut& operator*=(const Cut& cut);

private:
  std::set<std::string> dependencies_;
  std::string cut_string_;
};

Cut operator&&(const Cut& x, const Cut& y);
Cut operator||(const Cut& x, const Cut& y);
Cut operator*(const Cut& x, const Cut& y);

#endif
