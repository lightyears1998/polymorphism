// https://leetcode-cn.com/problems/sum-of-distances-in-tree/
// 树中距离之和
// 树形 DP

// dp[u] = SUM(dp[v] + sz[v]) (for v belongs to SON(u))
// 其中，
// dp[u]: 在 u 为根的树中，节点 u 到其所有节点的距离之和
// v 是 u 的直接后代
// sz[v] 是以 v 为根的子树的节点个数

// 换根操作时只需要考虑的更新 dp 和 sz。
// 注意换根只能在相邻的两个节点之间进行。

let vec: number[][]
let ans: number[]
let dp: number[], sz: number[]

function init(N: number, edges: number[][]) {
    vec = [], ans = [], dp = [], sz = []

    for (let i = 0; i < N; ++i) {
        vec[i] = []
    }

    for (const edge of edges) {
        vec[edge[0]].push(edge[1])
        vec[edge[1]].push(edge[0])
    }
}

function sumOfDistancesInTree(N: number, edges: number[][]): number[] {
    init(N, edges)

    prepareDp(0)
    calcDP(0)

    return ans
};

function prepareDp(node: number, parent?: number) {
    dp[node] = 0
    sz[node] = 1

    for (const child of vec[node]) {
        if (child !== parent) {
            prepareDp(child, node)
            dp[node] += dp[child] + sz[child]
            sz[node] += sz[child]
        }
    }
}

function calcDP(node: number, parent?: number) {
    ans[node] = dp[node]

    for (const child of vec[node]) {
        if (child === parent) {
            continue
        }

        const [dpNode, dpChild] = [dp[node], dp[child]]
        const [szNode, szChild] = [sz[node], sz[child]]

        dp[node] -= dpChild + szChild
        sz[node] -= szChild
        dp[child] += dp[node] + sz[node]
        sz[child] += sz[node]

        calcDP(child, node)

        dp[node] = dpNode
        sz[node] = szNode
        dp[child] = dpChild
        sz[child] = szChild
    }
}

/* -------------------------------- */

// 朴素做法（TLE）

const vec: Array<Array<number>> = []

function sumOfDistancesInTree(N: number, edges: number[][]): number[] {

    for (let i = 0; i < N; ++i) {
        vec[i] = []
    }

    for (const edge of edges) {
        vec[edge[0]].push(edge[1])
        vec[edge[1]].push(edge[0])
    }

    const ans = []
    for (let i = 0; i < N; ++i) {
        ans.push(bfs(0, i))
    }
    return ans
};

function bfs(dis: number, node: number, parent?: number): number {
    const children = vec[node]

    let ret = 0
    for (const child of children) {
        if (child !== parent) {
            ret += dis + 1 + bfs(dis + 1, child, node)
        }
    }
    return ret
}
