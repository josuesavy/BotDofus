#ifndef PLAYERSEARCHCHARACTERNAMEINFORMATION_H
#define PLAYERSEARCHCHARACTERNAMEINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/utils/io/type/FuncTree.h"

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