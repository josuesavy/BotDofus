#ifndef HUMANOPTIONFOLLOWERS_H
#define HUMANOPTIONFOLLOWERS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/look/IndexedEntityLook.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOption.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class HumanOptionFollowers : public HumanOption
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HumanOptionFollowers(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HumanOptionFollowers(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HumanOptionFollowers(FuncTree tree);
  HumanOptionFollowers();
  bool operator==(const HumanOptionFollowers &compared);

  QList<QSharedPointer<IndexedEntityLook>> followingCharactersLook;

private:
  void _followingCharactersLooktreeFunc(Reader *input);
  void _followingCharactersLookFunc(Reader *input);

  FuncTree _followingCharactersLooktree;
};

#endif // HUMANOPTIONFOLLOWERS_H