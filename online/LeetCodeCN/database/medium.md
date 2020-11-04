# Medium

## [1613](https://leetcode-cn.com/problems/find-the-missing-ids/) 找到遗失的 ID

关键是使用 `WITH RECURSIVE` 建立临时表。[PostgreSQL](https://www.postgresql.org/docs/8.4/queries-with.html)

``` sql
WITH RECURSIVE `t` AS (
    SELECT 1 AS `id`
    UNION ALL
    SELECT `id` + 1 FROM `t` WHERE `id` < 100
)
SELECT `id` AS `ids` FROM `t`
WHERE `id` <= (
    SELECT MAX(`customer_id`) FROM `Customers`
) AND `id` NOT IN (
    SELECT `customer_id` FROM `Customers`
)
ORDER BY `ids` ASC;
```

## [1596](https://leetcode-cn.com/problems/the-most-frequently-ordered-products-for-each-customer/) 每位顾客最经常订购的商品

``` sql
WITH `product_count` AS (
    SELECT `customer_id`, `product_id`, COUNT(*) AS `count`
    FROM `Orders`
    GROUP BY `customer_id`, `product_id`
), `most_product_count` AS (
    SELECT `customer_id`, MAX(`count`) AS `count` FROM `product_count`
    GROUP BY `customer_id`
)
SELECT `product_count`.`customer_id`, `product_count`.`product_id`, `Products`.`product_name` FROM `product_count`
INNER JOIN `most_product_count` USING (`customer_id`, `COUNT`)
INNER JOIN `Products` USING (`product_id`)
ORDER BY `customer_id` ASC, `product_id` ASC
```
