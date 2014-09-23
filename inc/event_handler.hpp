// event_handler: Defines reduced tree with RA4 variables

#ifndef H_EVENT_HANDLER
#define H_EVENT_HANDLER

#include <vector>
#include <string>
#include <utility>
#include <limits>
#include <stdint.h>
#include "ra4_objects.hpp"
#include "utilities.hpp"


using namespace std;

class event_handler : public ra4_objects{
public:
  explicit event_handler(const std::string &fileName);

  void ReduceTree(int Nentries, TString outFilename);
};

#endif
