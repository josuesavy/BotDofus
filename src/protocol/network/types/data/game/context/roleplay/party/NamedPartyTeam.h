#ifndef NAMEDPARTYTEAM_H
#define NAMEDPARTYTEAM_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class NamedPartyTeam : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NamedPartyTeam(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NamedPartyTeam(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NamedPartyTeam(FuncTree tree);
  NamedPartyTeam();
  bool operator==(const NamedPartyTeam &compared);

  uint teamId;
  QString partyName;

private:
  void _teamIdFunc(Reader *input);
  void _partyNameFunc(Reader *input);
};

#endif // NAMEDPARTYTEAM_H