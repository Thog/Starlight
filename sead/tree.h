#pragma once

#include "critical.h"
#include "heap.h"
#include "types.h"

namespace sead
{
    class TreeNode
    {
        public:
        TreeNode();

        void clearLinks();
        void pushBackChild(sead::TreeNode *child);
        void detachSubTree();
        void pushBackSibling(sead::TreeNode *sibling);
        void pushFrontChild(sead::TreeNode *child);
        void insertBeforeSelf(sead::TreeNode *node);
        void insertAfterSelf(sead::TreeNode *node);
        void detachAll();
        void clearChildLinksRecursively_();
        sead::TreeNode* findRoot();
        sead::TreeNode* findRoot() const;
        u32 countChildren() const;

        sead::TreeNode* mRoot; // _0
        sead::TreeNode* mChildNode; // _8
        u64 _10;
        u64 _18;
    };

    class MethodTreeNode : public sead::IDisposer
    {
        public:

        enum Condition
        {
            NODE_FRONT = 0,
            NODE_BACK = 1
        };

        virtual ~MethodTreeNode();

        void pushBackChild(sead::MethodTreeNode *);
        void lock_();
        void attachMutexRec_(sead::CriticalSection *) const;
        void unlock_();
        void pushFrontChild(sead::MethodTreeNode *);
        void detachAll();
        void call();
        void callRec_();
        sead::MethodTreeNode* find(sead::MethodTreeNode::Condition &);

        sead::TreeNode mRootNode; // _20
        u8 _40[0x78-0x40]; // not sure whats here
        sead::CriticalSection* mCritSection; // _78
    };
};