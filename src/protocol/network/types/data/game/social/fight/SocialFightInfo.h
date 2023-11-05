#ifndef SOCIALFIGHTINFO_H
#define SOCIALFIGHTINFO_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class SocialFightInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialFightInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialFightInfo(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialFightInfo(FuncTree tree);
  SocialFightInfo();
  bool operator==(const SocialFightInfo &compared);

  uint fightId;
  uint fightType;
  double mapId;

private:
  void _fightIdFunc(Reader *input);
  void _fightTypeFunc(Reader *input);
  void _mapIdFunc(Reader *input);
};

#endif // SOCIALFIGHTINFO_H