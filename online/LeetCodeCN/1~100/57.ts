// 57. 插入区间
// https://leetcode-cn.com/problems/insert-interval/

// 用了类似括号对的做法，
// 但直接模拟会更简单。

function insert(intervals: number[][], newInterval: number[]): number[][] {
    const [nodeA, nodeB] = [
        { val: newInterval[0], isOpen: true },
        { val: newInterval[1], isOpen: false }
    ]
    let [nodeAIsInserted, nodeBIsInserted] = [false, false]

    const nodes: Array<{ val: number, isOpen: boolean }> = []
    for (const interval of intervals) {
        const toBePushed = [
            { val: interval[0], isOpen: true }, { val: interval[1], isOpen: false }
        ]

        for (const node of toBePushed) {
            if (!nodeAIsInserted) {
                if (nodeA.val <= node.val) {
                    nodes.push(nodeA)
                    nodeAIsInserted = true
                }
            }
            if (nodeAIsInserted && !nodeBIsInserted) {
                if (nodeB.val <= node.val) {
                    nodes.push(nodeB)
                    nodeBIsInserted = true
                }
            }

            if (nodes.length > 0 && node.val === nodes[nodes.length - 1].val && node.isOpen && !nodes[nodes.length - 1].isOpen) {
                nodes.pop()
            } else {
                nodes.push(node)
            }
        }
    }

    if (!nodeAIsInserted) {
        nodes.push(nodeA)
    }

    if (!nodeBIsInserted) {
        nodes.push(nodeB)
    }

    const result: number[][] = []
    let openCount = 0, left = 0
    for (const node of nodes) {
        if (node.isOpen) {
            openCount++
            if (openCount === 1) {
                left = node.val
            }
        } else {
            openCount--
            if (openCount === 0) {
                result.push([left, node.val])
            }
        }
    }

    return result
};
