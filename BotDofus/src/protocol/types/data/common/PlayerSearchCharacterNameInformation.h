#ifndef PLAYERSEARCHCHARACTERNAMEINFORMATION_H
#define PLAYERSEARCHCHARACTERNAMEINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PlayerSearchCharacterNameInformation : public AbstractPlayerSearchInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PlayerSearchCharacterNameInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PlayerSearchCharacterNameInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PlayerSearchCharacterNameInformation(FuncTree tree);
  PlayerSearchCharacterNameInformation();
  bool operator==(const PlayerSearchCharacterNameInformation &compared);

  QString name;

private:
  void _nameFunc(Reader *input);
};

#endif // PLAYERSEARCHCHARACTERNAMEINFORMATION_H