#ifndef ALLIANCEVERSATILEINFORMATIONS_H
#define ALLIANCEVERSATILEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class AllianceVersatileInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceVersatileInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceVersatileInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceVersatileInformations(FuncTree tree);
  AllianceVersatileInformations();
  bool operator==(const AllianceVersatileInformations &compared);

  uint allianceId;
  uint nbGuilds;
  uint nbMembers;
  uint nbSubarea;

private:
  void _allianceIdFunc(Reader *input);
  void _nbGuildsFunc(Reader *input);
  void _nbMembersFunc(Reader *input);
  void _nbSubareaFunc(Reader *input);
};

#endif // ALLIANCEVERSATILEINFORMATIONS_H