# Easy

## [1350](https://leetcode-cn.com/problems/students-with-invalid-departments/) 院系无效的学生

``` sql
SELECT `id`, `name` FROM `students`
WHERE `department_id` NOT IN (
    SELECT `id` FROM `departments`
);
```

``` sql
--  Slower
SELECT `id`, `name` from `students`
WHERE NOT EXISTS (
    SELECT * FROM `departments` WHERE `students`.`department_id` = `departments`.`id`
);
```

## [1378](https://leetcode-cn.com/problems/replace-employee-id-with-the-unique-identifier/) 使用唯一标识码替换员工ID

``` sql
SELECT `unique_id`, `name`
FROM `Employees`
LEFT JOIN `EmployeeUNI` ON `Employees`.`id` = `EmployeeUNI`.`id`;
```

## [1068](https://leetcode-cn.com/problems/product-sales-analysis-i/) 产品销售分析

``` sql
SELECT `product_name`, `year`, `price`
FROM `Sales` INNER JOIN `Product`
USING (`product_id`); -- ON `Sales`.`product_id` = `Product`.`product_id`
```

## [1527](https://leetcode-cn.com/problems/patients-with-a-condition/) Patients With a Condition

``` sql
SELECT * FROM `Patients`
WHERE `conditions` LIKE "%DIAB1%";
```

## [1303](https://leetcode-cn.com/problems/find-the-team-size/) 求团队人数

``` sql
-- 窗口函数（推荐）
SELECT
    employee_id,
    COUNT(employee_id) OVER(PARTITION BY team_id) AS `team_size`
FROM `Employee`;
```

``` sql
-- 中间表
SELECT `employee_id`, `team_size`
FROM `Employee`
LEFT JOIN (
    SELECT `team_id`, COUNT(`team_id`) AS `team_size`
    FROM `Employee`
    GROUP BY `team_id`
) AS `Team` -- Every derived table must have its own alias
USING (`team_id`);
```

``` sql
-- 自连接 Self Join
SELECT `e1`.`employee_id`, COUNT(*) AS `team_size`
FROM `Employee` AS `e1`
INNER JOIN `Employee` AS `e2` USING (`team_id`)
GROUP BY `employee_id`
ORDER BY `employee_id`;
```

``` sql
-- 相关子查询
SELECT `e1`.`employee_id`, (
    SELECT COUNT(*) FROM `Employee` AS `e2`
    WHERE `e1`.`team_id` = `e2`.`team_id`
) AS `team_size`
FROM `Employee` AS `e1`;
```

## [613](https://leetcode-cn.com/problems/shortest-distance-in-a-line/) 直线上最短的距离

``` sql
SELECT MIN(ABS(`x1`.`x` - `x2`.`x`)) AS `shortest`
FROM `point` AS `x1`, `point` AS `x2`
WHERE `x1`.`x` != `x2`.`x`;
```

## [1609](https://leetcode-cn.com/problems/product-sales-analysis-ii/) 产品销售分析

``` sql
SELECT `product_id`, SUM(`quantity`) AS `total_quantity`
FROM `Sales`
GROUP BY `product_id`;
```

## [595](https://leetcode-cn.com/problems/big-countries/) 大的国家

``` sql
SELECT `name`, `population`, `area`
FROM `World`
WHERE `population` > 25000000 OR `area` > 3000000;
```

## [627](https://leetcode-cn.com/problems/swap-salary/) 交换工资

``` sql
-- CASE WHEN ... THEN ... ELSE ... END
UPDATE `salary` SET `sex` = CASE
    WHEN `sex` = 'm' THEN 'f'
    ELSE 'm'
END;
```

## [1251](https://leetcode-cn.com/problems/average-selling-price/) 平均售价

- `ROUND(value, precision)` `ROUND(3.14159, 2)` 四舍五入到两位小数
- `BETWEEN v1 AND v2` 值落在[v1, v2]闭区间上

``` sql
-- 相关子查询
SELECT
    `product_id`,
    ROUND(
        SUM((SELECT `price` * `units`
        FROM `Prices`
        WHERE
            `Prices`.`product_id` = `UnitsSold`.`product_id`
            AND `start_date` <= `purchase_date`
            AND `end_date` >= `purchase_date` -- `purchase_date` BETWEEN `start_date` AND `end_date`
        )) / SUM(`units`)
    , 2) AS `average_price`
FROM `UnitsSold`
GROUP BY `product_id`;
```

``` sql
-- （推荐）JOIN 临时表
-- Slower
SELECT
    `product_id`,
    ROUND(SUM(`sales`) / SUM(`units`), 2) AS `average_price`
FROM (
    SELECT
        `product_id`,
        `price` * `units` AS `sales`,
        `units`
    FROM `UnitsSold`
    INNER JOIN `Prices` USING (`product_id`)
    WHERE `purchase_date` BETWEEN `start_date` AND `end_date`
) AS `Summary`
GROUP BY `product_id`;
```

## [584](https://leetcode-cn.com/problems/find-customer-referee/) 寻找用户推荐人

- 当列可能为 `NULL`，务必考虑 `NULL` 的情况，使用 `IFNULL()`， `IS NULL` 等进行判定。

``` sql
SELECT `name` FROM `customer`
WHERE `referee_id` IS NULL OR `referee_id` != 2;
```

## [1517](https://leetcode-cn.com/problems/find-users-with-valid-e-mails/) 寻找拥有有效邮箱的用户

- MySQL [正则表达式](https://dev.mysql.com/doc/refman/8.0/en/regexp.html#operator_regexp)
- [MySQL Regular Expression on GeeksforGeeks](https://www.geeksforgeeks.org/mysql-regular-expressions-regexp/)

``` sql
SELECT * FROM `Users`
WHERE `mail` REGEXP "^[a-zA-Z]+[a-zA-Z0-9_./\-]*@leetcode.com$"
```

## [620](https://leetcode-cn.com/problems/not-boring-movies/) 有趣的电影

- `LIKE` 默认是大小写不敏感的，如果需要大小写敏感，则可以使用 `LIKE BINARY`。
- MySQL 5.6 与 8.0 使用了不同的单词边界，见 [StackOverflow 上的这个解答](https://stackoverflow.com/a/60906360/8762529)。

``` sql
SELECT * FROM `cinema`
WHERE `id` % 2 = 1 AND `description` NOT LIKE "%boring%"
ORDER BY `rating` DESC;
```

``` sql
-- 使用单词边界更严谨
SELECT * FROM `cinema`
WHERE `id` % 2 = 1 AND `description` NOT REGEXP "\\bboring\\b"
ORDER BY `rating` DESC;
```

## [196](https://leetcode-cn.com/problems/delete-duplicate-emails/) 删除重复的电子邮箱

注意到，这里如果只是使用一层 SELECT，MySQL 会报错。报错原因可参考 [StackOverflow](https://stackoverflow.com/a/9843719/8762529)。

``` sql
DELETE FROM `Person` WHERE `Id` NOT IN (
    SELECT `MinId` FROM (
        SELECT MIN(`Id`) AS `MinId` FROM `Person` GROUP BY `Email`
    ) AS `t`
)
```

## [175](https://leetcode-cn.com/problems/combine-two-tables/) 组合两个表

``` sql
SELECT `FirstName`, `LastName`, `City`, `State` FROM `Person`
LEFT OUTER JOIN `Address` USING (`PersonId`)
```
